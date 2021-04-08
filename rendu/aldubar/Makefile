# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 14:26:59 by aldubar           #+#    #+#              #
#    Updated: 2021/04/08 13:51:13 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	hotrace

SRCS		=	main.c \
			search.c \
			utils.c

CC		=	@clang

CFLAGS		=	-Wall -Wextra -Werror -O3

RM		=	@rm -rf

INC_DIR		=	./includes
LIB_DIR		=	./libft

OBJS		=	$(addprefix srcs/, $(SRCS:.c=.o))

OK		=	"\r[ \033[0;32mok\033[0m ]"

.c.o:
		$(CC) $(CFLAGS) -I includes -I libft -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(INC_DIR)/hotrace.h
		@make -s -C $(LIB_DIR)
		@echo "[....] Compiling hotrace\c"
		$(CC) $(CFLAGS) $(OBJS) -L$(LIB_DIR) -lft -o $@
		@echo $(OK)

all:		$(NAME)

clean:
		@make clean -s -C $(LIB_DIR)
		@echo "[....] Removing $(NAME) objects\c"
		$(RM) $(OBJS)
		@echo $(OK)

fclean:		clean
		@echo "[....] Removing libft.a\c"
		$(RM) libft/libft.a
		@echo $(OK)
		$(RM) $(NAME)
		@echo "[....] Removing $(NAME)\c"
		$(RM) $(NAME)
		@echo $(OK)

re:		fclean all

.PHONY:		all clean fclean re
