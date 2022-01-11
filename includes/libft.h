/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2022/01/11 09:27:54 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H


# include <netdb.h> // a verifier tout
# include <arpa/inet.h>
# include <netinet/in.h>
# include <stdlib.h>
# include <string.h>
# include <sys/socket.h>
# include <sys/types.h> // fin de verif tout



# include <sys/types.h> // open
# include <sys/stat.h> // open
# include <fcntl.h> // open

# include <unistd.h> // write and read
# include <stdio.h> // printf

# include <stdlib.h> // malloc and free


# include <string.h> // strcmp

#include <strings.h> // bzero

# define COLOR_GREEN "\033[0;32m"
# define COLOR_RED "\033[0;31m"
# define COLOR_YELLOW "\033[0;33m"
# define COLOR_NEUTRAL "\033[0m"

# define SEND_SIZE 2048 // taille des paquets a envoyer
# define PORT 26565 // port utilise pour la connection
# define SA struct sockaddr // raccourci pour la structure TCP


typedef struct j_point
{
	int				error; // Si error != 0 alors une erreur est survenue, avec pour reference sa valeur
	int				fd_s; // file descriptor sending
	int				fd_r; // file descriptor receiving
	long	long	i; // number of strings send
	
}			t_point;

/*			IN FT_ERROR.C			*/

void	ft_error_with_mess(t_point *data); // message d'erreurs personnalises
void	ft_usage(void); // explique l'usage du programme


/*			IN FT_ANA_FLAG.C		*/

void	ft_ana_flag(char *str1, char *str2,t_point *data); //  analyse les arguments


/*			IN FT_SEND.C			*/

void	ft_is_openable(t_point *data, char *str2); // verifie si le fichier existe
void	ft_send_in_tcp(t_point *data, char *str2); // fonction principale d'envoi
void	ft_main_send(t_point *data); // lancement de toutes les merdes pour le protocole tcp
void	ft_send(int connfd, t_point *data);

/*			IN FT_RECEIVE.C			*/

void	ft_main_receive(t_point *data);
void	ft_receive(int sockfd, t_point *data);
void	ft_receiving_in_tcp(t_point *data, char *str2);
void	ft_create_file_and_open_it(t_point *data, char *str2); // cree un fichier vierge et l'ouvre

#endif
