# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 11:42:37 by tlegrand          #+#    #+#              #
#    Updated: 2023/02/06 22:36:47 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# search for FORCE $(shell dirname ) cc -I -L -lft dependance? .d pathsubst 
# architecture ? dir inclue ? dir lib ? dir srcs ? 

NAME		=	push_swap

SRCS		= 	push_swap.c ft_atol.c solver.c smol_sort.c utils.c utils_debug.c\
				stack_manipulator.c stack_operator_basic.c  stack_operator_print.c stack_info.c ft_create_stack.c ft_next.c\

DIR_OBJS	=	.objs/
LIST_OBJS	=	${SRCS:.c=.o}
OBJS		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS}}

HEADER		=	push_swap.h \


FLAGS		=	-Wall -Wextra -Werror 

RM			=	rm -rf

DIR_LIBFT	=	libft/
LIBFT		=	$(addprefix $(DIR_LIBFT), libft.a)



all:			$(NAME)



$(NAME):		$(LIBFT) $(OBJS)
				$(CC) $(FLAGS) -o $(NAME) $(OBJS) ${LIBFT}

$(LIBFT): FORCE
	$(MAKE) -C $(DIR_LIBFT)

nn	:
	norminette ${SRCS} ${HEADER} 

$(DIR_OBJS)%.o: %.c
				mkdir -p $(shell dirname $@)
				$(CC) $(FLAGS) -I . -c $< -o $@

clean:
				$(MAKE) -C $(DIR_LIBFT) clean
				$(RM) $(DIR_OBJS)

fclean: clean
				$(MAKE) -C $(DIR_LIBFT) fclean
				$(RM) $(NAME)

re:				fclean
				$(MAKE) all


FORCE:

.PHONY : all clean fclean re nn FORCE