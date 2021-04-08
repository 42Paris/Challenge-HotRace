NAME = hotrace
CC = g++

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): main.o
	$(CC) -o hotrace main.o

main.o: main.cpp
	$(CC) -c main.cpp

re: fclean all
clean:
	@/bin/rm -rf main.o

fclean:
	@/bin/rm -rf main.o
	@/bin/rm -rf $(NAME)
