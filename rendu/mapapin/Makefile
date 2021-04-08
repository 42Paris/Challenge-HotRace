# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <mapapin@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 22:59:37 by user42            #+#    #+#              #
#    Updated: 2021/04/07 22:59:38 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace

C = clang
CFLAGS = -Wall -Wextra -Werror -O3

SRCS = main.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(C) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
