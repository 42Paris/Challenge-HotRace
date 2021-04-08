# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/08 14:05:19 by ashishae          #+#    #+#              #
#    Updated: 2021/04/08 00:12:31 by ashishae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c hashmap.c
OBJS = $(SRCS:.c=.o)
NAME = hotrace
CFLAGS = -Wall -Wextra -Werror -Ofast -march=native
CC = clang


all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		clean fclean re all
