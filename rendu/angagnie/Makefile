NAME = hotrace
SRC = main.c
CC = gcc
CPPFLAGS += -Wall -Werror -Wextra -Ofast -march=native
SIZE ?= 16384

all: ${NAME}

$(NAME): $(SRC)
	$(CC) $(CPPFLAGS) -o $@ $^ -DHASHMAP_CAPACITY=$(SIZE)

clean:
	@echo Clean

fclean:	clean
	rm -f ${NAME}

re: fclean all
