/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:58:10 by guderram          #+#    #+#             */
/*   Updated: 2022/01/11 05:43:54 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	main(int argc, char **argv)
{
	t_point	data;

	data.error = 0;
	if (argc == 1 || argc > 3)
	{
		data.error = 1;
		ft_error_with_mess(&data);
		return (-1);
	}
	ft_ana_flag(argv[1], argv[2], &data);
	if (data.error != 0)
		ft_error_with_mess(&data);
	printf("ALL IS FINISH\n");
	return (0);
}
