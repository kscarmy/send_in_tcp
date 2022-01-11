#include "../includes/libft.h"

void	ft_ana_flag(char *str1, char *str2,t_point *data) //  analyse les arguments
{
	if (strcmp(str1, "-s") == 0 && str2 != NULL)
	{
		printf("is sending\n");
		ft_send_in_tcp(data, str2);
		//fonction emetteur
	}
	else if (strcmp(str1, "-r") == 0 && str2 != NULL)
	{
		printf("is waiting\n");
		ft_receiving_in_tcp(data, str2);
		// fonciton reception
	}
	else
	{
		data->error = 2;
	}
}
