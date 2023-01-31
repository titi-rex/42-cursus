# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 11:42:37 by tlegrand          #+#    #+#              #
#    Updated: 2023/01/31 13:54:19 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRCS		= 	push_swap.c ft_atol.c solver.c smol_sort.c utils.c utils_debug.c\
				stack_manipulator.c stack_operator_basic.c  stack_operator_print.c stack_info.c ft_create_stack.c ft_next.c\

DIR_OBJS	=	.objs/
LIST_OBJS	=	${SRCS:.c=.o}
OBJS		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS}}

HEADER		=	push_swap.h \

LIB			=	libft/libft.a\

FLAGS		=	-Wall -Wextra -Werror -I .

RM			=	rm -rf


all		: 	${NAME}

${NAME}	:	lib ${DIR_OBJS} ${OBJS}
		${CC} ${FLAGS} ${OBJS} ${LIB} -o ${NAME}

leaks	: ${DIR_OBJS} ${OBJS}
		leaks --atExit -- ./${NAME} 

nn	:
	norminette ${SRCS} ${HEADER} 

lib	:
	${MAKE} -C libft

${DIR_OBJS}%.o	:	%.c ${HEADER} 
				${CC} ${FLAGS} -c $< -o $@

${DIR_OBJS}	:
			mkdir ${DIR_OBJS}

clean	:
		${RM} ${DIR_OBJS}
		make -C libft clean

fclean	:	clean
		${RM} ${NAME}
		make -C libft fclean

re	:	fclean
	${MAKE} all

.PHONY : all clean fclean re bonus nn test