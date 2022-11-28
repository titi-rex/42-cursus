# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 14:03:05 by tlegrand          #+#    #+#              #
#    Updated: 2022/11/28 16:03:19 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	= 	ft_printf.c ft_putchar.c ft_putstr.c ft_putadr.c ft_putnbr_base.c \
			
SRCS_T	=	main.c

DIR_OBJS	=	.objs/
LIST_OBJS	=	${SRCS:.c=.o}
OBJS		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS}}
LIST_OBJS_T	=	${SRCS_T:.c=.o}
OBJS_T		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS_T}}

HEADER	=	ft_printf.h

RM		=	rm -rf

FLAGS	=	-Wall -Wextra -Werror -I ${HEADER}

all	: ${NAME}

${NAME}	:	${DIR_OBJS} ${OBJS}
		${AR} rcs $@ ${OBJS}


${DIR_OBJS}%.o	:	%.c ${HEADER} Makefile
				${CC} ${FLAGS} -c $< -o $@

${DIR_OBJS}	:
			mkdir ${DIR_OBJS}

check	:	${DIR_OBJS} ${OBJS} ${OBJS_T}
		${CC} ${FLAGS} ${OBJS} ${OBJS_T} && ./a.out && ${RM} ${TOBJS} a.out

nn	:
	norminette ${SRCS} ${SRCS_B} ${HEADER}

clean	:
		${RM} ${DIR_OBJS}

fclean	:	clean
		${RM} ${NAME}

re	:	fclean
	${MAKE} all

.PHONY : all clean fclean re bonus