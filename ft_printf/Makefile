# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 20:46:19 by tlegrand          #+#    #+#              #
#    Updated: 2024/06/20 17:34:37 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	PROJECT VARIABLES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#

#	==============================	NAMES	==============================	#
NAME		=	libftprintf.a

#	==============================	SOURCES	==============================	#
DIR_SRCS		=	src/
LST_SRCS		= 	ft_printf.c  \
					ft_putadr.c ft_putnbr_base.c ft_putchar.c ft_putstr.c 
SRCS			=	${addprefix ${DIR_SRCS}, ${LST_SRCS}}

LST_SRCS_B		= 	ft_printf_bonus.c write_bonus.c padding_bonus.c \
					get_flags_bonus.c get_value_bonus.c extract_number_bonus.c \
					utils_bonus.c utils_math_bonus.c 
SRCS_B			=	${addprefix ${DIR_SRCS}, ${LST_SRCS_B}}

#	==============================	OBJECTS	==============================	#
DIR_OBJS	=	.objs/
OBJS		=	${patsubst ${DIR_SRCS}%.c, ${DIR_OBJS}%.o, ${SRCS}} 


#	==============================	HEADERS	==============================	#
HEADER			=	ft_printf.h
HEADER_B		=	ft_printf_bonus.h

#	==============================	COMMANDS	==============================	#
CC 			=	cc
MKDIR 		=	mkdir
RM			=	rm -rf
MAKE		=	make


#	==============================	FLAGS	==============================	#
CFLAGS		=	-Wall -Wextra -Werror
AFLAGS		=	rcs



#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	RULES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#
.PHONY : all clean fclean re bonus FORCE nn

#	==============================	BASIC	==============================	#
all		:	${NAME}

bonus	:
		@${MAKE} SRCS="${SRCS_B}" HEADER="${HEADER_B}"

clean	:
		@${RM} ${DIR_OBJS}

fclean	:	clean
		@${RM} ${NAME} ${NAME_B}
		@printf "$(GREEN)All clean !\n$(END)"

re		:	fclean
		@${MAKE} all


#	==============================	COMPILATION	==============================	#
${NAME}			:	${DIR_OBJS} ${OBJS}
				@${AR} ${AFLAGS} ${NAME} ${OBJS} 
				@printf "$(GREEN_LIGHT)${NAME} created !\n$(END)"

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADER}  
				@printf "$(ORANGE)Making $@...\n$(END)"
				@${CC} ${CFLAGS} -c $< -o $@



#	==============================	UTILS/LIB	==============================	#
${DIR_OBJS}	:
			@${MKDIR} ${DIR_OBJS}
			
nn			:
			@norminette $(sort ${SRCS} ${SRCS_B} ${HEADER} ${HEADER_B})



#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	OPERATING VARIABLES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#

#	==============================	COLORS	==============================	#
BLACK		=	\033[0;30m
RED			=	\033[0;31m
GREEN		=	\033[0;32m
ORANGE		=	\033[0;33m
BLUE		=	\033[0;34m
PURPLE		=	\033[0;35m
CYAN		=	\033[0;36m
GRAY_LIGHT	=	\033[0;37m
GRAY_DARK	=	\033[1;30m
RED_LIGHT	=	\033[1;31m
GREEN_LIGHT	=	\033[1;32m
YELLOW 		=	\033[1;33m
BLUE_LIGHT	=	\033[1;34m
VIOLET		=	\033[1;35m
CYAN		=	\033[1;36m
WHITE		=	\033[1;37m
END			=	\033[0m
UNDERLINE	=	\033[4m
REV			=	\033[7m
ERASE		=	\033[2K
RERASE		=	\r\033[2K