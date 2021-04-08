# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 11:24:00 by geargenc          #+#    #+#              #
#    Updated: 2021/04/08 11:40:06 by geargenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT			:

NAME			=	hotrace

CC				= 	gcc

CFLAGS			=	-Wall -Wextra -Werror -I includes/

OFLAGS			=	-O3

FILES			=	hotrace.c \
					readstdin.c

SRC_DIR			=	src/

SRC				=	$(addprefix $(SRC_DIR), $(FILES))

OBJ_DIR			=	obj/

OBJ				=	$(addprefix $(OBJ_DIR), $(FILES:.c=.o))

DEP_DIR			=	dep/

DEP				=	$(addprefix $(DEP_DIR), $(FILES:.c=.d))

all				:	$(NAME)

$(DEP_DIR)%.d	:	$(SRC_DIR)%.c
	@mkdir -p $(DEP_DIR)
	@$(CC) $(CFLAGS) -MM $< -MT $(OBJ_DIR)$*.o -MF $@
	@printf "\r\E[K\033[1;33mCreated : $@\033[0m"

-include $(DEP)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@
	@printf "\r\E[K\033[1;33mCreated : $@\033[0m"

$(NAME)			:	$(OBJ)
	@$(CC) $(CFLAGS) $(OFLAGS) $(OBJ) -o $@
	@printf "\033[1;32mCreated : $@\033[0m\n"

clean			:
	@rm -rf obj
	@printf "\033[1;31mRemoved : $(OBJ_DIR)\033[0m\n"
	@rm -rf dep
	@printf "\033[1;31mRemoved : $(DEP_DIR)\033[0m\n"

fclean			:	clean
	@rm -f $(NAME)
	@printf "\033[1;31mRemoved : $(NAME)\033[0m\n"

re				:
	@$(MAKE) $(MFLAGS) fclean
	@$(MAKE) $(MFLAGS) all

.PHONY			:	all clean fclean re