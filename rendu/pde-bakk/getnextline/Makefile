# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: peerdb <peerdb@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/09/24 12:54:54 by peerdb        #+#    #+#                  #
#    Updated: 2021/04/05 15:37:53 by pde-bakk      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a

FLAGS = -Wall -Wextra -Werror -ansi -pedantic -std=c89
ifdef DEBUG
  FLAGS += -g -fsanitize=address
else
  FLAGS += -Ofast
endif

FILES = srcs/get_next_line.c srcs/get_next_line_utils.c
OBJS = $(FILES:.c=.o)

# COLORS
PINK = \x1b[35;01m
BLUE = \x1b[34;01m
YELLOW = \x1b[33;01m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
WHITE = \x1b[31;37m
RESET = \x1b[0m

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@printf "$(GREEN)Done creating getnextline.a$(RESET)\n"

%.o: %.c
	@$(CC) -c $^ -o $@ $(FLAGS) -I include_internal

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
