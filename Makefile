# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 11:42:37 by tlegrand          #+#    #+#              #
#    Updated: 2023/01/25 20:49:37 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

DIR_OBJS	=	.objs/

SRCS		= 	pipex.c utils.c format.c ft_cat_fd.c
LIST_OBJS	=	${SRCS:.c=.o}
OBJS		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS}}

HEADER		=	pipex.h \

LIB			=	libft/libft.a\

FLAGS		=	-Wall -Wextra -Werror -I .

RM			=	rm -rf


all		: 	${NAME}

${NAME}	:	lib ${DIR_OBJS} ${OBJS}
		${CC} ${FLAGS} ${OBJS} ${LIB} -o ${NAME}


leaks	: ${NAME}
		leaks --atExit -- ./${NAME}

nn	:
	/home/reina/.local/bin/norminette ${SRCS} ${HEADER}

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

.PHONY : all clean fclean re bonus lib n