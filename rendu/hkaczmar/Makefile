NAME		=	hotrace

SRC			=	main.c\
				nodestuff.c\

OBJ			=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Werror -Wextra -Ofast

CC			=	clang

all:		$(NAME)

%.o:	%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re

