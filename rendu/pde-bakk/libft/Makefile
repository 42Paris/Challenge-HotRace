# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pde-bakk <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 13:45:00 by pde-bakk      #+#    #+#                  #
#    Updated: 2021/04/05 16:06:30 by pde-bakk      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC = $(addprefix srcs/, $(FILES))

OBJ = $(SRC:.c=.o)

BONUSFILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
SRC_BONUS = $(addprefix srcs/, $(BONUSFILES))
OBJ_BONUS = $(SRC_BONUS:.c=.o)

HEADER = -I include

FLAGS = -Wall -Werror -Wextra
ifdef DEBUG
  FLAGS += -g -fsanitize=address
else
  FLAGS += -Ofast
endif

# COLORS
PINK = \x1b[35;01m
BLUE = \x1b[34;01m
YELLOW = \x1b[33;01m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
WHITE = \x1b[31;37m
RESET = \x1b[0m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(YELLOW)Linking libft.a...$(RESET)\n"
	@ar -rc $(NAME) $(OBJ)
	@printf "$(YELLOW)Done!$(RESET)\n"

%.o: %.c
	@$(CC) -c $^ -o $@ $(FLAGS) $(HEADER)

clean:
	@/bin/rm -f *.o *~ *.gch

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

bonus: $(OBJ) $(OBJ_BONUS)
	ar -rc $(NAME) $(OBJ) $(BONUSOBJ)
