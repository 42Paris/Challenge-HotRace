##################### CONTAINER FILES #######################
INCLUDES	= Map.hpp MapNode.hpp
INC_DIR		= ./
INCLUDES 	:= $(addprefix ${INC_DIR}, ${INCLUDES})
#############################################################


######################### SRCS FILES ########################
SRCS	= hotrace.cpp
SRC_DIR	= ./
SRCS 	:= $(addprefix ${SRC_DIR}, ${SRCS})
OBJS			= ${SRCS:.cpp=.o}
#############################################################


CPP			= clang++
CFLAGS		= #-Wall -Wextra -Werror #-fsanitize=address -fno-omit-frame-pointer 
NAME		= hotrace
OPTI_FLAGS	= -O3 #-march=native
CFLAGS 		+= ${OPTI_FLAGS}


.cpp.o:		${SRCS} ${INCLUDES}
			${CPP} ${CFLAGS} ${INC_DIRS} -c $^ -o ${<:.cpp=.o}

all:		${NAME}

${NAME}:	${OBJS} ${INCLUDES}
			${CPP} ${CFLAGS} ${INC_DIRS} -o ${NAME} ${OBJS}

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME} 

re :		fclean all
