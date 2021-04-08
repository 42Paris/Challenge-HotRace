NAME = hotrace

SRC = HotRace.c Hashmap.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -O -Ofast

CC = clang

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re