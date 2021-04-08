SRCS = dict.c hotrace.c

OBJS = ${SRCS:.c=.o}

NAME = hotrace

FLAGS = -Werror -Wall -Wextra -Ofast

CC = cc

RM = rm -rf

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I .

$(NAME): ${OBJS}
	${CC} -o ${NAME} ${OBJS}

all: $(NAME)

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re .c.o
