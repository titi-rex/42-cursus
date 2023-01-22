# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 11:42:37 by tlegrand          #+#    #+#              #
#    Updated: 2023/01/22 14:41:37 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk

DIR_OBJS	=	.objs/

NAME_S		=	server 
SRCS_S		= 	server.c server_handler.c binary_coding.c \
				utils.c
LIST_OBJS_S	=	${SRCS_S:.c=.o}
OBJS_S		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS_S}}

NAME_C		=	client
SRCS_C		=	client.c binary_coding.c client_sender.c \
				utils.c
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
		leaks --atExit -- ./${NAME} 

nn	:
	norminette ${SRCS} ${SRCS_B} ${HEADER} ${HEADER_B}

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