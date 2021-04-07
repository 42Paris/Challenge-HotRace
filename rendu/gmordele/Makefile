NAME = hotrace

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRC = hotrace.c

OBJ = hotrace.o

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all