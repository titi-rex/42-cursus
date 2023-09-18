# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 11:48:58 by tlegrand          #+#    #+#              #
#    Updated: 2023/09/18 10:10:23 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone


SRC		=	megaphone.cpp

OBJ		=	${SRC:.cpp=.o}


CC		=	c++
RM		=	rm -f

CFLAGS	=	-Wall -Werror -Wextra -std=c++98



.PHONY	:	all clean fclean re

all 	:	${NAME}

clean	:
		$(RM) ${OBJ}

fclean	:	clean
		$(RM) ${NAME}

re		:	fclean all
		

${NAME}	:	${OBJ} 
		$(CC) ${CFLAGS} $^ -o $@

%.o		:	%.cpp $(HDR)
		${CC} ${CFLAGS} -c $< -o $@