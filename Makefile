CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = client.c\
		server.c\
		utils.c\

SRC_BONUS = client_bonus.c\
			server_bonus.c\
			utils.c\

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus
NAME_CLIENT = client
NAME_SERVER = server

NAME = $(NAME_SERVER) $(NAME_CLIENT)

all: $(NAME)

$(NAME_SERVER): server.o utils.o
		$(CC) server.o utils.o -o $(NAME_SERVER)

$(NAME_CLIENT): client.o utils.o
		$(CC) client.o utils.o -o $(NAME_CLIENT)
	
bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	
$(NAME_SERVER_BONUS): server_bonus.o utils.o
		$(CC) server_bonus.o utils.o -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): client_bonus.o utils.o
		$(CC) client_bonus.o utils.o -o $(NAME_CLIENT_BONUS)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
