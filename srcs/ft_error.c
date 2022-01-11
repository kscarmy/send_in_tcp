#include "../includes/libft.h"

void	ft_error_with_mess(t_point *data) // message d'erreurs personnalises
{
	if (data->error == 1) // nombre arguments invalide
	{
		printf("%sERROR : %sNumber of arguments invalid\n", COLOR_RED, COLOR_NEUTRAL);
		ft_usage();
	}
	if (data->error == 2) // flags invalides
	{
		printf("%sERROR : %sInvalid arguments\n", COLOR_RED, COLOR_NEUTRAL);
		ft_usage();
	}
	if (data->error == 3) // fichier inexistant
	{
		printf("%sERROR : %sInvalid file or path to file\n", COLOR_RED, COLOR_NEUTRAL);
	}
	if (data->error == 4) // erreur pendant la creation du fichier de reception !
	{
		printf("%sERROR : Creation of file failure !\n", COLOR_RED);
	}
}

void	ft_usage(void) // explique l'usage du programme
{
	printf("%sUsage : %s./sendtcp %s[FLAGS] %s'path_file_to_send OR name_file_received'\n", COLOR_YELLOW, COLOR_NEUTRAL, COLOR_GREEN, COLOR_NEUTRAL);
	printf("%s[FLAGS] :%s '-s' for sending OR 'r' for reception\n", COLOR_GREEN, COLOR_NEUTRAL);
}