# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 20:46:19 by tlegrand          #+#    #+#              #
#    Updated: 2024/06/20 18:03:16 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	PROJECT VARIABLES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#

#	==============================	NAMES	==============================	#
NAME		=	minishell


#	==============================	SOURCES	==============================	#
DIR_SRCS		=	src/

LST_SRCS		=	main.c \
					signal.c \
					utils.c \
					term.c \
					debug.c 
SRCS			=	${addprefix ${DIR_SRCS}, ${LST_SRCS}}

DIR_SRCS_BI		=	srcs/built_in/
LST_SRCS_BI		=	ft_is_bi.c bi_cd.c bi_echo.c bi_pwd.c  bi_exit.c bi_env.c bi_export.c bi_type.c bi_unset.c bi_clear.c bi_loulou.c bi_titi.c
SRCS_BI			=	${addprefix ${DIR_SRCS_BI}, ${LST_SRCS_BI}}

DIR_SRCS_ENV	=	srcs/env/
LST_SRCS_ENV	=	env_init.c env_utils.c
SRCS_ENV		=	${addprefix ${DIR_SRCS_ENV}, ${LST_SRCS_ENV}}

DIR_SRCS_EXE	=	srcs/execution/
LST_SRCS_EXE	=	exe_cmd.c exe_utils.c \
					exe_dup_redirect.c exe_dup_pipe.c 
SRCS_EXE		=	${addprefix ${DIR_SRCS_EXE}, ${LST_SRCS_EXE}}

DIR_SRCS_PARSE	=	srcs/parsing/
LST_SRCS_PARSE	=	parsing.c get_path.c ft_here_doc.c \
					parsing_expansion.c parsing_bloc_utils.c \
					parsing_utils_expansion.c \
					parsing_quotes.c parsing_protect.c \
					parsing_quotes_utils.c \
					parsing_export.c \
					ft_split_bis.c \
					parsing_redirection.c parsing_utils_redirection.c
SRCS_PARSE		=	${addprefix ${DIR_SRCS_PARSE}, ${LST_SRCS_PARSE}}

DIR_SRCS_PROMPT	=	srcs/prompt/
LST_SRCS_PROMPT	=	prompt.c prompt_git.c prompt_pwd.c 
SRCS_PROMPT		=	${addprefix ${DIR_SRCS_PROMPT}, ${LST_SRCS_PROMPT}}

DIR_SRCS_STRUCT	=	srcs/structure/
LST_SRCS_STRUCT	=	s_line_basic.c \
					s_cmd_basic.c s_cmd_operator.c \
					s_redirect_basic.c s_redirect_operator.c \
					s_var_env_basic.c s_var_env_operator.c 
SRCS_STRUCT		=	${addprefix ${DIR_SRCS_STRUCT}, ${LST_SRCS_STRUCT}}


#	==============================	OBJECTS	==============================	#
DIR_OBJS	=	.objs/
OBJS		=	${patsubst ${DIR_SRCS}%.c, ${DIR_OBJS}%.o, ${SRCS}} \
				${patsubst ${DIR_SRCS_BI}%.c, ${DIR_OBJS}%.o, ${SRCS_BI}} \
				${patsubst ${DIR_SRCS_STRUCT}%.c, ${DIR_OBJS}%.o, ${SRCS_STRUCT}} \
				${patsubst ${DIR_SRCS_PARSE}%.c, ${DIR_OBJS}%.o, ${SRCS_PARSE}} \
				${patsubst ${DIR_SRCS_EXE}%.c, ${DIR_OBJS}%.o, ${SRCS_EXE}} \
				${patsubst ${DIR_SRCS_PROMPT}%.c, ${DIR_OBJS}%.o, ${SRCS_PROMPT}} \
				${patsubst ${DIR_SRCS_ENV}%.c, ${DIR_OBJS}%.o, ${SRCS_ENV}}

#	==============================	HEADERS	==============================	#
DIR_HEADER	=	include/
LST_HDR		=	${NAME}.h structure.h mycolors.h
HEADER		=	${addprefix ${DIR_HEADER}, ${LST_HDR}}


#	==============================	LIBRARY	==============================	#
DIR_LIBFT	=	libft/
LIBFT		=	$(addprefix $(DIR_LIBFT), libft.a)


#	==============================	COMMANDS	==============================	#
CC 			=	cc
MKDIR 		=	mkdir -p
RM			=	rm -rf
MAKE		=	make -s


#	==============================	FLAGS	==============================	#
CFLAGS		=	-Wall -Wextra -Werror -I${DIR_HEADER} 
RFLAGS		=	-lreadline -lft -ltermcap 
FTFLAGS		=	-L${DIR_LIBFT} -lft


#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	RULES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#
.PHONY : all clean fclean re bonus FORCE nn

#	==============================	BASIC	==============================	#
all		:	${NAME}

clean	:
		@${RM} ${DIR_OBJS}
		@$(MAKE) -C ${DIR_LIBFT} clean

fclean	:	clean
		@${RM} ${NAME} ${NAME_B}
		@$(MAKE) -C ${DIR_LIBFT} fclean
		@printf "$(GREEN)All clean !\n$(END)"

re		:	fclean
		@${MAKE} all


#	==============================	COMPILATION	==============================	#
${NAME}			:	${LIBFT} ${DIR_OBJS} ${OBJS}
				@${CC} ${CFLAGS} ${OBJS} ${FTFLAGS} ${RFLAGS} -o ${NAME}
				@printf "$(GREEN_LIGHT)${NAME} created !\n$(END)"


${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADER}
				@printf "$(YELLOW)Making $@...\n$(END)"
				@${CC} ${CFLAGS} -c $< -o $@

${DIR_OBJS}%.o	:	${DIR_SRCS_BI}%.c ${HEADER}
				@printf "$(YELLOW)Making $@...\n$(END)"
				@${CC} ${CFLAGS} -c $< -o $@

${DIR_OBJS}%.o	:	${DIR_SRCS_STRUCT}%.c ${HEADER}
				@printf "$(YELLOW)Making $@...\n$(END)"
				@${CC} ${CFLAGS} -c $< -o $@

${DIR_OBJS}%.o	:	${DIR_SRCS_PARSE}%.c ${HEADER}
				@printf "$(YELLOW)Making $@...\n$(END)"
				@${CC} ${CFLAGS} -c $< -o $@

${DIR_OBJS}%.o	:	${DIR_SRCS_EXE}%.c ${HEADER}
				@printf "$(YELLOW)Making $@...\n$(END)"
				@${CC} ${CFLAGS} -c $< -o $@

${DIR_OBJS}%.o	:	${DIR_SRCS_ENV}%.c ${HEADER}
				@printf "$(YELLOW)Making $@...\n$(END)"
				@${CC} ${CFLAGS} -c $< -o $@

${DIR_OBJS}%.o	:	${DIR_SRCS_PROMPT}%.c ${HEADER}
				@printf "$(YELLOW)Making $@...\n$(END)"
				@${CC} ${CFLAGS} -c $< -o $@

#	==============================	UTILS/LIB	==============================	#
${DIR_OBJS}	:
			@${MKDIR} ${DIR_OBJS}
			
nn			:
			@norminette $(sort ${DIR_SRCS}  ${HEADER} )

$(LIBFT)	:	FORCE
			@$(MAKE) -C ${DIR_LIBFT}

FORCE		:



#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	OPERATING VARIABLES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#

#	==============================	COLORS	==============================	#
BLACK		=	\033[0;30m
RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
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
BOLD		=	\033[1m
FAINT		=	\033[2m
ITALIC		=	\033[3m
UNDERLINE	=	\033[4m
BLINK_SLOW	=	\033[5m
BLINK_FAST	=	\033[6m
BLINK_OFF	=	\033[25m
REV_V		=	\033[7m
CONCEAL		=	\033[8m
CONCEAL_OFF	=	\033[28m
CROSS_OUT	=	\033[9m
CROSS_OUT_O	=	\033[29m
ERASE		=	\033[2K
RERASE		=	\r\033[2K
