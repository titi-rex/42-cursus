# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 11:48:58 by tlegrand          #+#    #+#              #
#    Updated: 2023/10/10 11:20:38 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	animal


HDR		=	Animal.hpp Dog.hpp Cat.hpp Brain.hpp

SRC		=	Animal.cpp Dog.cpp Cat.cpp Brain.cpp main.cpp

OBJ_DIR	=	.obj/
OBJ_LST	=	${SRC:.cpp=.o}
OBJ		=	$(addprefix $(OBJ_DIR), $(OBJ_LST))

CC		=	c++
RM		=	rm -rf

CFLAGS	=	-Wall -Werror -Wextra -std=c++98



.PHONY	:	all clean fclean re

all 	:	${NAME}

clean	:
		$(RM) $(OBJ_DIR)

fclean	:	clean
		$(RM) ${NAME}

re		:	fclean all
		

${NAME}	:	$(OBJ_DIR) ${OBJ} 
		$(CC) ${CFLAGS} $(OBJ) -o $@

$(OBJ_DIR)%.o	:	%.cpp $(HDR)
		${CC} ${CFLAGS} -c $< -o $@

$(OBJ_DIR)	:
			@mkdir -p $(OBJ_DIR)