# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 11:42:37 by tlegrand          #+#    #+#              #
#    Updated: 2024/06/20 17:38:26 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	get_next_line

SRCS		=	src/get_next_line.c src/get_next_line_utils.c 

SRCS_B		=	src/get_next_line_bonus.c src/get_next_line_utils_bonus.c 

SRCS_T		=	src/main.c 



OBJS		=	${SRCS:.c=.o}
OBJS_B		=	${SRCS_B:.c=.o}
OBJS_T		=	${SRCS_T:.c=.o}

HEADER		=	get_next_line.h 

HEADER_B	=	get_next_line_bonus.h 

RM			=	rm -rf

FLAGS		=	-Wall -Wextra -Werror -I .


all		: 	test

test	:	${OBJS} ${OBJS_T} ${HEADER}
		${CC} ${FLAGS} ${OBJS} ${OBJS_T} -o test

test_b	:	${OBJS_B} ${OBJS_T}
		${CC} ${FLAGS} ${OBJS_B} ${OBJS_T} -o test
nn		:
	norminette ${SRCS} ${SRCS_B} ${HEADER} ${HEADER_B}

%.o		:	%.c ${HEADER} 
		${CC} ${FLAGS} -c $< -o $@



clean	:
		${RM} ${OBJS} ${OBJS_B} ${OBJS_T}

fclean	:	clean
		${RM} test

re	:	fclean
	${MAKE} all

.PHONY : all clean fclean re bonus nn test