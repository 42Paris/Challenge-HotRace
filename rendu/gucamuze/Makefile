NAME	=	hotrace
CC		=	gcc
RM		=	rm -f

CFILES	= 	main.c \
			chained_list.c \
			hash_table.c \
			nodes.c \
			utils.c 

OFILES	= 	${CFILES:.c=.o}

.c.o:
			${CC} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OFILES}
				$(CC) $^ -o ${NAME}

fsanitize:	${OFILES}
				${CC} -fsanitize=address $^ -o ${NAME}

clean:
				${RM} ${OFILES}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:	all clean fsanitize fclean re ${NAME}
