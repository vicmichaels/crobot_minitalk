NAME		=	server
SRC_SERVER	=	server.c utils.c
OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

NAME2		=	client
SRC_CLIENT	=	client.c utils.c
OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

all:		$(NAME) $(NAME2)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

$(NAME):	$(OBJ_SERVER)
			$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME)

$(NAME2):	$(OBJ_CLIENT)
			$(CC) $(CFLAGS)	$(OBJ_CLIENT) -o $(NAME2)

clean:
			$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean:		clean
			$(RM) $(NAME) $(NAME2)

re:			fclean all

.PHONY: 	re clean fclean all