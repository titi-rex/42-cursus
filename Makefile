# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 11:42:37 by tlegrand          #+#    #+#              #
#    Updated: 2023/02/12 19:53:24 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	PROJECT VARIABLES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#

#	==============================	NAMES	==============================	#
NAME		=	minitalk
NAME_S		=	server 
NAME_C		=	client


#	==============================	SOURCES	==============================	#
DIR_SRCS	=	srcs/
LST_SRCS_S	= 	server.c utils.c
SRCS_S		=	${addprefix ${DIR_SRCS}, ${LST_SRCS_S}}
LST_SRCS_C	=	client.c utils.c
SRCS_C		=	${addprefix ${DIR_SRCS}, ${LST_SRCS_C}}


#	==============================	OBJECTS	==============================	#
DIR_OBJS	=	.objs/
OBJS_S		=	${patsubst ${DIR_SRCS}%.c, ${DIR_OBJS}%.o, ${SRCS_S}}
OBJS_C		=	${patsubst ${DIR_SRCS}%.c, ${DIR_OBJS}%.o, ${SRCS_C}}


#	==============================	HEADERS	==============================	#
HEADER		=	minitalk.h 


#	==============================	LIBRARY	==============================	#
DIR_LIBFT	=	libft/
LIBFT		=	$(addprefix $(DIR_LIBFT), libft.a)


#	==============================	COMMANDS	==============================	#
CC 			=	cc
MKDIR 		=	mkdir -p
RM			=	rm -rf
MAKE		=	make -s


#	==============================	FLAGS	==============================	#
CFLAGS		=	-Wall -Wextra -Werror



#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	RULES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#
.PHONY : all clean fclean re FORCE nn

#	==============================	BASIC	==============================	#
all		: 	${NAME}

clean	:
		@${RM} ${DIR_OBJS}
		@${MAKE} -C $(DIR_LIBFT) clean

fclean	:	clean
		@${RM} ${NAME_S} ${NAME_C}
		@${MAKE} -C $(DIR_LIBFT) fclean
		@printf "$(GREEN)All clean !\n$(END)"

re		:	fclean
		${MAKE} all
	

#	==============================	COMPILATION	==============================	#
${NAME}			:	$(LIBFT) ${NAME_S} ${NAME_C}

${NAME_S}		:	${DIR_OBJS} ${OBJS_S}
				@${CC} ${CFLAGS} ${OBJS_S} ${LIBFT} -o ${NAME_S}
				@printf "$(GREEN_LIGHT)${NAME_S} created !\n$(END)"

${NAME_C}		:	${DIR_OBJS} ${OBJS_C}
				@${CC} ${CFLAGS} ${OBJS_C} ${LIBFT} -o ${NAME_C}
				@printf "$(GREEN_LIGHT)${NAME_C} created !\n$(END)"

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADER}
				@printf "$(ORANGE)Making $@...\n$(END)"
				@${CC} ${CFLAGS} -c $< -o $@


#	==============================	UTILS/LIB	==============================	#
${DIR_OBJS}	:
			@${MKDIR} ${DIR_OBJS}

$(LIBFT)	: FORCE
			@$(MAKE) -C $(DIR_LIBFT)

nn			:
			@norminette ${SRCS_S} ${SRCS_C} ${HEADER}

FORCE		:



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
