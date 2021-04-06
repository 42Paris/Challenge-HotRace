# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: peerdb <peerdb@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/02 21:53:48 by peerdb        #+#    #+#                  #
#    Updated: 2020/10/06 12:19:22 by peerdb        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a

CXXFLAGS = -W -Wall -Wextra -Werror -pedantic -ansi -std=c++98
ifdef DEBUG
 FLAGS += -g -fsanitize=address
else
 FLAGS += -Ofast
endif
FILES = get_next_line.cpp
OBJ = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) -rcs $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I .

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) *.dSYM
	
re: fclean all

test: re
	$(CXX) $(CXXFLAGS) main.cpp $(NAME) -o test

.PHONY: clean fclean re all
