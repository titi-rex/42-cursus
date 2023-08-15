# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 11:48:58 by tlegrand          #+#    #+#              #
#    Updated: 2023/08/15 22:15:58 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	repertory


HDR		=	PhoneBook.hpp Contact.hpp

SRC		=	main.cpp PhoneBook.cpp Contact.cpp

OBJ_DIR	=	.obj/
OBJ_LST	=	${SRC:.cpp=.o}
OBJ		=	$(addprefix $(OBJ_DIR), $(OBJ_LST))

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
		

${NAME}	:	$(OBJ_DIR) ${OBJ} 
		@$(CC) $(OBJ) -o $@
		@printf "$(GREEN_LIGHT)$@ created !\n$(END)"

$(OBJ_DIR)%.o	:	%.cpp $(HDR)
		@printf "$(YELLOW)Making $@...\n$(END)"
		@${CC} ${CFLAGS} -c $< -o $@

$(OBJ_DIR)	:
			@mkdir -p $(OBJ_DIR)