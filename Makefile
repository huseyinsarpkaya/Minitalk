NAME = minitalk.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

SRC = client.c\
		server.c\
		utils.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re