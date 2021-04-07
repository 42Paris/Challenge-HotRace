# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 16:30:57 by asoursou          #+#    #+#              #
#    Updated: 2021/04/07 19:58:02 by asoursou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= hotrace
SRC			:= dict.c main.c rbtree.c str.c
CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror -Wpedantic -Wvla -Ofast -I./inc
OBJ			:= $(SRC:%.c=%.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$<

%.o: %.c hotrace.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re run
