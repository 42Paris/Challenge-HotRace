# ___COMPILATION___

C_COMPILER= clang
FLAGS= -Wall -Wextra -Werror -O2
SRCS=	srcs/main.c\
		srcs/list/ft_lstadd_front.c\
		srcs/list/ft_lstclear.c\
		srcs/list/ft_lstdelone.c\
		srcs/list/ft_lstnew.c\
		srcs/hash_map/hash_map.c\
		srcs/signal_handler/sigint_catcher.c\
		srcs/hash_map/pair.c

NAME= hotrace
OBJS= ${SRCS:.c=.o}
INCLUDE_DIRS = -I . -I ./srcs/list/ -I ./srcs/hash_map/ -I srcs/IO/ -I srcs/signal_handler/


.c.o:
	@printf "${LIGHT_BLUE}=>	"
	${C_COMPILER} ${FLAGS} ${INCLUDE_DIRS} -c $< -o ${<:.c=.o}
	@printf "${NC}"

# ___COLORS___

GREEN=\033[0;32m
LIGHT_BLUE=\033[0;34m
RED=\033[0;31m
YELLOW=\033[0;33m
NC=\033[0m

all: ${NAME}

${NAME}: ${OBJS}
	@printf "${YELLOW}=>	"
	${C_COMPILER} ${FLAGS} ${INCLUDE_DIRS} ${OBJS} -o ${NAME}
	@echo "${GREEN}✓ ${NAME} compiled${NC}"

start: all
	@./${NAME}

valgrind_start: all
	@valgrind --leak-check=full --show-leak-kinds=definite ./${NAME}

clean:
	@printf "${RED}X "
	rm -rf ${OBJS}
	@printf "${NC}"
	@echo "${GREEN}✓ ${NAME} clean${NC}"

fclean: clean
	@printf "${RED}X "
	rm -rf ${NAME}
	@printf "${NC}"

re: fclean all

.PHONY: all clean fclean re start

