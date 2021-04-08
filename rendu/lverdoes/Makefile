# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/07 16:00:30 by lverdoes      #+#    #+#                  #
#    Updated: 2021/04/07 23:52:59 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	hotrace

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -O3 $(INCL)
INCL		=	-I$(INCL_DIR)
INCL_DIR	=	includes/
SRC_DIR		=	src/

SRC_FILES	=	main.c parse.c get_line.c keyword_find.c keyword_new.c

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

.PHONY: clean fclean re

clean:
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f .DS_Store
	/bin/rm -f $(NAME)

re: fclean all
