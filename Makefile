# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 14:03:05 by tlegrand          #+#    #+#              #
#    Updated: 2023/01/21 15:50:46 by tlegrand         ###   ########.fr        #
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

LIB_MAC 	=	libft/libft.a minilibx/libmlx.a 

LIB_LINUX	=	libft/libft.a /usr/local/lib/libmlx.a

RM			=	rm -rf

FLAGS		=	-Wall -Wextra -Werror -I .

MLXFLAGS_MAC	=	-L minilibx/ -lmlx -framework OpenGL -framework AppKit

MLXFLAGS_LINUX	=	-Lmlx_linux -lmlx_Linux -L/usr/local/lib -Imlx_linux -lXext -lX11 -lm -lz 

all	: ${NAME}

${NAME}	:	lib ${DIR_OBJS} ${OBJS}
		${CC} ${MLXFLAGS} ${OBJS} ${LIB} -o ${NAME}

${NAME}_L	:	lib ${DIR_OBJS} ${OBJS}
		${CC} ${OBJS} ${LIB_LINUX} ${MLXFLAGS_L} -o ${NAME}
		
leaks	: ${NAME}
		leaks --atExit -- ./${NAME}

nn	:
	norminette ${SRCS} ${SRCS_B} ${HEADER}

lib	:
	${MAKE} -C libft
#	${MAKE} -C minilibx

${DIR_OBJS}%.o	:	%.c ${HEADER} 
				${CC} ${FLAGS} -I/usr/local/include -Imlx_linux -O3 -c $< -o $@

${DIR_OBJS}	:
			mkdir ${DIR_OBJS}

clean	:
		${RM} ${DIR_OBJS}
#		${MAKE} -C libft clean

fclean	:	clean
		${RM} ${NAME}
		${MAKE} -C libft fclean
#		${MAKE} -C minilibx clean

re	:	fclean
	${MAKE} all
	${MAKE} -C libft re
#	${MAKE} -C minilibx re

.PHONY : all clean fclean re bonus nn test