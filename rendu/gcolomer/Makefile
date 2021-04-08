NAME	=	hotrace
SRCS	=	hash.c main.c slot.c struct.c tab.c
OBJS	=	$(SRCS:.c=.o)
CC		=	clang
CFLAGS	=	-Werror -Wall -Wextra
INCLUDE	=	-I hash.h -I slot.h -I tab.h

all :		${NAME}
.PHONY:		all

%.o : 		%.c
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INCLUDE}


${NAME} :	${OBJS}
			${CC} ${CFLAGS} ${OBJS} ${INCLUDE} -o ${NAME}


clean :
			rm -f ${OBJS}
.PHONY: 	clean


fclean :	clean
			rm -rf ${NAME}
.PHONY:		fclean


re :		fclean all
.PHONY:		re
