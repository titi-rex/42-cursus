/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:22:41 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/13 14:41:27 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

t_stack		*ft_stacknew(int value);
t_stack		*ft_stack_penultimate(t_stack *head);
t_stack		*ft_stacklast(t_stack *stack);
t_stack		*ft_stacksearch(t_stack *head, int value);
int			ft_stackmax(t_stack *stack);
int			ft_stackmin(t_stack *stack);
void		ft_stackadd_back(t_stack **head, t_stack *new);
void		ft_stackadd_front(t_stack **stack, t_stack *new);
void		ft_stackclear(t_stack **head);
t_stack		*ft_create_stack(char **arg, int n_arg);
int			ft_print_stack(t_stack *head);
void		double_print(t_stack *a, t_stack *b);

void		*ft_error(int wit);
int			ft_is_valid(char *arg);
long int	ft_atol(const char *str);

void		ft_swap(t_stack **start);
void		ft_swap_value(t_stack *head);
void		ft_push(t_stack **start_src, t_stack **start_dst);
void		ft_rotate(t_stack **start);
void		ft_rotate_reverse(t_stack **start);

int			ft_stacksize(t_stack *head);
int			ft_searchmin(t_stack *head, int size);
void		ft_stackdel(t_stack **head, int target);

int			ft_is_sorted(t_stack *stack, int start, int end);
int			ft_solver1(t_stack **stack_a);
int			ft_solver2(t_stack **stack_a);
int			ft_partition(t_stack **start_a, int start, int end);

#endif