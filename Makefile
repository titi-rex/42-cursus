# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 11:42:37 by tlegrand          #+#    #+#              #
#    Updated: 2023/02/12 20:23:38 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	PROJECT VARIABLES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#

#	==============================	NAMES	==============================	#
NAME		=	push_swap


#	==============================	SOURCES	==============================	#
DIR_SRCS	=	srcs/
LST_SRCS	= 	push_swap.c ft_atol.c solver.c smol_sort.c utils.c utils_debug.c \
				stack_manipulator.c stack_operator_basic.c  stack_operator_print.c stack_info.c ft_create_stack.c ft_next.c
SRCS		=	${addprefix ${DIR_SRCS}, ${LST_SRCS}}


#	==============================	OBJECTS	==============================	#
DIR_OBJS	=	.objs/
OBJS		=	${patsubst ${DIR_SRCS}%.c, ${DIR_OBJS}%.o, ${SRCS}}


#	==============================	HEADERS	==============================	#
HEADER		=	push_swap.h


#	==============================	LIBRARY	==============================	#
DIR_LIBFT	=	libft/
LIBFT		=	$(addprefix $(DIR_LIBFT), libft.a)


#	==============================	COMMANDS	==============================	#
CC 			=	cc
MKDIR 		=	mkdir -p
RM			=	rm -rf
MAKE		=	make -s


#	==============================	FLAGS	==============================	#
CFLAGS		=	-Wall -Wextra -Werror 



#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	RULES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#
.PHONY : all clean fclean re FORCE nn

#	==============================	BASIC	==============================	#
all		:	$(NAME)

clean	:
		@$(RM) $(DIR_OBJS)
		@$(MAKE) -C $(DIR_LIBFT) clean

fclean	:	clean
		@$(RM) $(NAME)
		@$(MAKE) -C $(DIR_LIBFT) fclean
		@printf "$(GREEN)All clean !\n$(END)"

re		:	fclean
		@$(MAKE) all


#	==============================	COMPILATION	==============================	#
$(NAME)			:	$(LIBFT) ${DIR_OBJS} $(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) ${LIBFT} -o $(NAME)
				@printf "$(GREEN_LIGHT)${NAME} created !\n$(END)"

$(DIR_OBJS)%.o	:	${DIR_SRCS}%.c ${HEADER}
				@printf "$(ORANGE)Making $@...\n$(END)"
				@$(CC) $(CFLAGS) -c $< -o $@


#	==============================	UTILS/LIB	==============================	#
${DIR_OBJS}	:
			@${MKDIR} ${DIR_OBJS}

$(LIBFT)	:	FORCE
			@$(MAKE) -s -C $(DIR_LIBFT)

nn			:
			@norminette ${SRCS} ${HEADER} 

FORCE		:



#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	OPERATING VARIABLES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#

#	==============================	COLORS	==============================	#
BLACK		=	\033[0;30m
RED			=	\033[0;31m
GREEN		=	\033[0;32m
ORANGE		=	\033[0;33m
BLUE		=	\033[0;34m
PURPLE		=	\033[0;35m
CYAN		=	\033[0;36m
GRAY_LIGHT	=	\033[0;37m
GRAY_DARK	=	\033[1;30m
RED_LIGHT	=	\033[1;31m
GREEN_LIGHT	=	\033[1;32m
YELLOW 		=	\033[1;33m
BLUE_LIGHT	=	\033[1;34m
VIOLET		=	\033[1;35m
CYAN		=	\033[1;36m
WHITE		=	\033[1;37m
