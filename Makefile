# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 11:42:37 by tlegrand          #+#    #+#              #
#    Updated: 2022/12/25 15:57:48 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

NAME_B		=	checker

SRCS		= 	push_swap.c utils.c ft_atol.c solver1.c solver2.c\
				ft_create_stack.c stack_operator_basic.c stack_manipulator.c \

SRCS_B		=	 \

DIR_OBJS	=	.objs/
LIST_OBJS	=	${SRCS:.c=.o}
OBJS		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS}}
LIST_OBJS_B	=	${SRCS:.c=.o}
OBJS_B		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS_B}}

HEADER		=	push_swap.h \

HEADER_B	=	\

LIB			=	libft.a \

FLAGS		=	-Wall -Wextra -Werror -I ${HEADER}

RM			=	rm -rf


all		: 	${NAME}

${NAME}	:	${DIR_OBJS} ${OBJS}
		${CC} ${FLAGS} ${OBJS} ${LIB} -o ${NAME}

leaks	: ${DIR_OBJS} ${OBJS} ${OBJS_T}
		leaks --atExit -- ./${NAME} 

leaks_b	: ${DIR_OBJS} ${OBJS_B} ${OBJS_T}
		leaks --atExit -- ./${NAME_B} 

nn	:
	norminette ${SRCS} ${SRCS_B} ${HEADER} ${HEADER_B}


${DIR_OBJS}%.o	:	%.c ${HEADER} 
				${CC} ${FLAGS} -c $< -o $@

${DIR_OBJS}	:
			mkdir ${DIR_OBJS}

clean	:
		${RM} ${DIR_OBJS}

fclean	:	clean
		${RM} ${NAME}

re	:	fclean
	${MAKE} all

.PHONY : all clean fclean re bonus nn test