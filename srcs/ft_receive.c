#include "../includes/libft.h"

void	ft_create_file_and_open_it(t_point *data, char *str2) // cree un fichier vierge et l'ouvre
{
	FILE *fp;
	fp = fopen (str2, "w+");
	fclose(fp);
	data->fd_r = open(str2, O_WRONLY);
	if (data->fd_s == -1)
	{
		data->error = 4;
	}
}

void ft_receive(int sockfd, t_point *data)
{
	char buff[SEND_SIZE];
	char *end = "4c075aba26f1fdf8228619c6289e2fd2a05ba613";
	// int i = 0;

	printf("START RECEIVE\n");
	read(sockfd, buff, SEND_SIZE);
	write(data->fd_r, buff, SEND_SIZE);
	while (strncmp(buff, end, 40) != 0)
	{
		read(sockfd, buff, SEND_SIZE);
		if (strncmp(buff, end, 40) != 0)
			write(data->fd_r, buff, SEND_SIZE);
		// i ++;
	}
	// read(sockfd, buff, SEND_SIZE);
	// printf("buff : %s\n", buff);
	printf("END RECEIVE\n");

	// for (;;) {
	// 	bzero(buff, sizeof(buff));
	// 	printf("Enter the string : ");
	// 	n = 0;
	// 	while ((buff[n++] = getchar()) != '\n')
	// 		;
	// 	write(sockfd, buff, sizeof(buff));
	// 	bzero(buff, sizeof(buff));
	// 	read(sockfd, buff, sizeof(buff));
	// 	printf("From Server : %s", buff);
	// 	if ((strncmp(buff, "exit", 4)) == 0) {
	// 		printf("Client Exit...\n");
	// 		break;
	// 	}
	// }
}

void	ft_main_receive(t_point *data)
{
	int sockfd;
	struct sockaddr_in servaddr;

	// socket create and varification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("78.196.240.69");
	// servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT);

	// connect the client socket to server socket
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
		printf("connection with the server failed...\n");
		exit(0);
	}
	else
		printf("connected to the server..\n");

	// function for chat
	ft_receive(sockfd, data);

	// close the socket
	close(sockfd);
}

void	ft_receiving_in_tcp(t_point *data, char *str2)
{
	ft_create_file_and_open_it(data, str2);
	if (data->error == 0)
		ft_main_receive(data);
	close(data->fd_r);
}