#include "../includes/libft.h"

void	ft_is_openable(t_point *data, char *str2) // verifie si le fichier existe
{
	char buff[SEND_SIZE];
	data->fd_s = open(str2, O_RDONLY);
	data->i = 0;
	if (data->fd_s == -1)
	{
		data->error = 3;
	}
	else
	{
		while (read(data->fd_s, buff, SEND_SIZE) > 0)
		{
			// printf("OK\n");
			data->i = data->i + 1;
		}
		// printf("ztf\n");
	}
	close(data->fd_s);
	data->fd_s = open(str2, O_RDONLY);
}

// Function designed for chat between client and server.
void ft_send(int connfd, t_point *data)
{
	char buff[SEND_SIZE];
	// long long i = 0;
	char size[42];
	// char *end = "4c075aba26f1fdf8228619c6289e2fd2a05ba613";
	sprintf(size, "%lld", data->i);
	write(connfd, size, 42);
	// printf("size : %s\n", size);
	// size = itoa(data->i);
	bzero(buff, SEND_SIZE);
	printf("START SEND %lld\n", data->i);


	while (read(data->fd_s, buff, SEND_SIZE) > 0)
	{
		// printf("%s", buff);
		write(connfd, buff, SEND_SIZE);
		usleep(50);
	}
	// printf("\n%s\n", end);
	// write(connfd, end, 40);
	printf("STOP SEND\n");

	// // infinite loop for chat
	// for (;;) {
	// 	bzero(buff, SEND_SIZE);

	// 	// read the message from client and copy it in buffer
	// 	read(connfd, buff, sizeof(buff));
	// 	// print buffer which contains the client contents
	// 	printf("From client: %s\t To client : ", buff);
	// 	bzero(buff, SEND_SIZE);
	// 	n = 0;
	// 	// copy server message in the buffer
	// 	while ((buff[n++] = getchar()) != '\n')
	// 		;

	// 	// and send that buffer to client
	// 	write(connfd, buff, sizeof(buff));

	// 	// if msg contains "Exit" then server exit and chat ended.
	// 	if (strncmp("exit", buff, 4) == 0) {
	// 		printf("Server Exit...\n");
	// 		break;
	// 	}
	// }
}

void	ft_main_send(t_point *data) // lancement de toutes les merdes pour le protocole tcp
{
	int sockfd, connfd;
	unsigned int len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
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
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");

	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");
	len = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, &len);
	if (connfd < 0) {
		printf("server accept failed...\n");
		exit(0);
	}
	else
		printf("server accept the client...\n");

	// Function for chatting between client and server
	ft_send(connfd, data);

	// After chatting close the socket
	// printf("in main send %d\n", data->error);
	close(sockfd);
}

void	ft_send_in_tcp(t_point *data, char *str2) // fonction principale d'envoi
{

	ft_is_openable(data, str2);
	if (data->error == 0)
		ft_main_send(data);
	close(data->fd_s);
}