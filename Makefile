# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 14:03:05 by tlegrand          #+#    #+#              #
#    Updated: 2023/01/31 13:55:58 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS		= 	main.c map_get.c map_check.c map_init.c utils.c
			
DIR_OBJS	=	.objs/
LIST_OBJS	=	${SRCS:.c=.o}
OBJS		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS}}
LIST_OBJS_B	=	${SRCS:.c=.o}
OBJS_B		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS_B}}

HEADER		=	so_long.h 

LIB			=	libft/libft.a /usr/local/lib/libmlx.a

RM			=	rm -rf

FLAGS		=	-Wall -Wextra -Werror -I .

MLXFLAGS	=	-Lmlx_linux -lmlx_Linux -L/usr/local/lib -Imlx_linux -lXext -lX11 -lm -lz 


all	: ${NAME}

${NAME}	:	lib ${DIR_OBJS} ${OBJS}
		${CC} ${OBJS} ${LIB} ${MLXFLAGS} -o ${NAME}
		
leaks	: ${NAME}
		leaks --atExit -- ./${NAME}

nn	:
	norminette ${SRCS} ${SRCS_B} ${HEADER}

lib	:
	${MAKE} -C libft

${DIR_OBJS}%.o	:	%.c ${HEADER} 
				${CC} ${FLAGS} -I/usr/local/include -Imlx_linux -O3 -c $< -o $@

${DIR_OBJS}	:
			mkdir ${DIR_OBJS}

clean	:
		${RM} ${DIR_OBJS}

fclean	:	clean
		${RM} ${NAME}
		${MAKE} -C libft fclean

re	:	fclean
	${MAKE} all
	${MAKE} -C libft re

.PHONY : all clean fclean re lib leaks bonus nn test