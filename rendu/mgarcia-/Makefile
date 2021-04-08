NAME	= hotrace

SRCS	= main.c

OBJS	= ${SRCS:.c=.o}

CC	= clang

CFLAGS	= -Wall -Werror -Wextra -Ofast

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	

all:		${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re: 	fclean all
