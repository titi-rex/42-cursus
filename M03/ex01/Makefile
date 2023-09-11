# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 11:48:58 by tlegrand          #+#    #+#              #
#    Updated: 2023/09/11 16:56:17 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	robot


HDR		=	ClapTrap.hpp ScavTrap.hpp

SRC		=	ClapTrap.cpp ScavTrap.cpp main.cpp

OBJ_DIR	=	.obj/
OBJ_LST	=	${SRC:.cpp=.o}
OBJ		=	$(addprefix $(OBJ_DIR), $(OBJ_LST))

CC		=	c++
RM		=	rm -rf

CFLAGS	=	-Wall -Wextra -std=c++98



.PHONY	:	all clean fclean re

all 	:	${NAME}

clean	:
		@$(RM) $(OBJ_DIR)

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