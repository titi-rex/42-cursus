# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 14:03:05 by tlegrand          #+#    #+#              #
#    Updated: 2022/11/19 16:46:20 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -I .

SRCS = 	 \
		
SRCS_B = \

TSRCS = main.c

OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

TOBJS = ${TSRCS:.c=.o}

HEADER = libftprintf.h

all : ${NAME}

${NAME} :	${OBJS}
		${AR} rcs $@ $^

bonus :	${OBJS} ${OBJS_B}
		${AR} rcs ${NAME} $^

%.o :	%.c ${HEADER} Makefile
		${CC} ${FLAGS} -c $< -o $@

check :	${OBJS} ${TOBJS}
		${CC} ${FLAGS} ${OBJS} ${TOBJS} && ./a.out && ${RM} ${TOBJS} a.out

nn :
	norminette ${SRCS} ${SRCS_B} ${HEADER}

clean :
		${RM} ${OBJS} ${OBJS_B}

fclean :	clean
		${RM} ${NAME}

re :	fclean
	${MAKE} all

.PHONY : all clean fclean re bonus%