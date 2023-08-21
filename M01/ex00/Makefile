# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 11:48:58 by tlegrand          #+#    #+#              #
#    Updated: 2023/08/21 19:44:37 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	zombie


HDR		=	Zombie.hpp

SRC		=	main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJ_DIR	=	.obj/
OBJ_LST	=	${SRC:.cpp=.o}
OBJ		=	$(addprefix $(OBJ_DIR), $(OBJ_LST))

CC		=	c++
RM		=	rm -rf

CFLAGS	=	-Wall -Werror -Wextra -std=c++98



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