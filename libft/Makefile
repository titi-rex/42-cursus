# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 14:39:06 by tlegrand          #+#    #+#              #
#    Updated: 2023/01/20 11:04:38 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

FLAGS	=	-Wall -Wextra -Werror 

DIR_SRCS	=	srcs/
LST_SRCS	= 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_isascii.c \
				ft_toupper.c ft_tolower.c ft_atoi.c \
				ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_strlen.c \
				ft_strdup.c ft_calloc.c ft_strlcpy.c ft_strlcat.c \
				ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
				ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_base.c \
				get_next_line.c get_next_line_utils.c
SRCS		=	${addprefix ${DIR_SRCS}, ${LST_SRCS}}

OBJS	=	${SRCS:.c=.o}

HEADER 		=	libft.h

all : ${NAME}

${NAME} :	${OBJS}
		${AR} rcs $@ $^

%.o	:	%.c ${HEADER} 
				${CC} ${FLAGS} -c $< -o $@

clean	:
		${RM} ${OBJS}

fclean	:	clean
		${RM} ${NAME}

re	:	fclean
	${MAKE} all

.PHONY : all clean fclean re