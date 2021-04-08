# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 23:24:10 by ngragas           #+#    #+#              #
#    Updated: 2021/04/07 23:24:34 by ngragas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace
CFLAGS = -Wall -Wextra -Werror -Ofast
SRC =	hotrace.c		\
# 		hotrace_utils.c

OBJ = $(SRC:.c=.o)
HEADER = hotrace.h

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re