NAME = hotrace

CC = clang

CFLAGS = -Wall -Wextra -Werror -O3

SRC = main.c

OBJ = $(SRC:c=o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
