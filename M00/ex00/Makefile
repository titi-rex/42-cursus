# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 11:48:58 by tlegrand          #+#    #+#              #
#    Updated: 2023/09/13 22:02:00 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone


SRC		=	megaphone.cpp

OBJ		=	${SRC:.cpp=.o}


CC		=	c++
RM		=	rm -f

CFLAG	=	-Wall -Werror -Wextra -std=c++98



.PHONY	:	all clean fclean re

all 	:	${NAME}

clean	:
		@$(RM) ${OBJ}

fclean	:	clean
		@$(RM) ${NAME}
		@printf "$(GREEN)All clean !\n$(END)"

re		:	fclean all
		

${NAME}	:	${OBJ} 
		@$(CC) ${CFLAGS} $^ -o $@
		@printf "$(GREEN_LIGHT)$@ created !\n$(END)"

%.o		:	%.cpp $(HDR)
		@printf "$(YELLOW)Making $@...\n$(END)"
		@${CC} ${CFLAGS} -c $< -o $@