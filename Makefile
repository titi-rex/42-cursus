# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 11:42:37 by tlegrand          #+#    #+#              #
#    Updated: 2023/04/01 11:51:21 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	get_next_line

SRCS		= 	get_next_line.c get_next_line_utils.c \

SRCS_B		=	get_next_line_bonus.c get_next_line_utils_bonus.c \
			
SRCS_T		=	main.c \

DIR_OBJS	=	.objs/
LIST_OBJS	=	${SRCS:.c=.o}
OBJS		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS}}
LIST_OBJS_B	=	${SRCS:.c=.o}
OBJS_B		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS_B}}
LIST_OBJS_T	=	${SRCS_T:.c=.o}
OBJS_T		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS_T}}

HEADER		=	get_next_line.h \

HEADER_B	=	get_next_line_bonus.h \

RM			=	rm -rf

FLAGS		=	-Wall -Wextra -Werror -I ${HEADER}


all		: 	test

test	:	${DIR_OBJS} ${OBJS} ${OBJS_T}
		${CC} ${FLAGS} ${OBJS} ${OBJS_T} 

leaks	: ${DIR_OBJS} ${OBJS} ${OBJS_T}
		${CC} ${FLAGS} ${OBJS} ${OBJS_T} && leaks --atExit -- ./a.out

test_b	:	${DIR_OBJS} ${OBJS_B} ${OBJS_T}
		${CC} ${FLAGS} ${OBJS_B} ${OBJS_T} && ./a.out

leaks_b	: ${DIR_OBJS} ${OBJS_B} ${OBJS_T}
		${CC} ${FLAGS} ${OBJS_B} ${OBJS_T} && leaks --atExit -- ./a.out

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