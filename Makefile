NAME = sendtcp

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_C = srcs/ft_error.c\
		srcs/ft_ana_flag.c\
		srcs/ft_send.c\
		srcs/ft_receive.c\

MAIN_C = srcs/main.c\

OBJS = ft_error.o\
		ft_ana_flag.o\
		ft_send.o\
		ft_receive.o\


all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) $(SRC_C) $(MAIN_C) -o $(NAME)
clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
	@rm -rf $(OBJS)
