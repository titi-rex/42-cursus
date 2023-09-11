# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 11:48:58 by tlegrand          #+#    #+#              #
#    Updated: 2023/09/11 21:53:16 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone


HDR		=	

SRC		=	megaphone.cpp

OBJ		=	${SRC:.cpp=.o}


CC		=	c++
rm		=	rm -f

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