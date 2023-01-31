# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 11:42:37 by tlegrand          #+#    #+#              #
#    Updated: 2023/01/31 13:50:53 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk

DIR_OBJS	=	.objs/

NAME_S		=	server 
SRCS_S		= 	server.c utils.c
LIST_OBJS_S	=	${SRCS_S:.c=.o}
OBJS_S		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS_S}}

NAME_C		=	client
SRCS_C		=	client.c utils.c
LIST_OBJS_C	=	${SRCS_C:.c=.o}
OBJS_C		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS_C}}

HEADER		=	minitalk.h \

LIB			=	libft/libft.a\

FLAGS		=	-Wall -Wextra -Werror -I .

RM			=	rm -rf


all		: 	${NAME}

${NAME}	:	lib server client

server	:	${DIR_OBJS} ${OBJS_S}
		${CC} ${FLAGS} ${OBJS_S} ${LIB} -o ${NAME_S}

client	:	${DIR_OBJS} ${OBJS_C}
		${CC} ${FLAGS} ${OBJS_C} ${LIB} -o ${NAME_C}

leaks	: ${NAME}
		leaks --atExit -- ./${NAME_S}
		leaks --atExit -- ./${NAME_C}

nn	:
	/home/reina/.local/bin/norminette ${SRCS_S} ${SRCS_C} ${HEADER}

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
		${RM} ${NAME_S} ${NAME_C}
		make -C libft fclean

re	:	fclean
	${MAKE} all

.PHONY : all clean fclean re nn lib leaks 