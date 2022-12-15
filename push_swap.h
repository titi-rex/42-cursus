/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:22:41 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/15 18:31:27 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"
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
void		ft_stackadd_back(t_stack **head, t_stack *new);
void		ft_stackclear(t_stack **head);
t_stack		*ft_create_stack(char **arg, int n_arg);
int			ft_print_stack(t_stack *head);

void		*ft_error(int wit);
int			ft_is_valid(char *arg);
long int	ft_atol(const char *str);

void		ft_swap(t_stack *head);
void		ft_push(t_stack **head_src, t_stack **head_dst);
void		ft_rotate(t_stack **head);
void		ft_rotate_reverse(t_stack **head);

int			ft_stacksize(t_stack *head);
int			ft_searchmin(t_stack *head, int size);
int			ft_solver1(t_stack **stack_a);
void		ft_stackdel(t_stack **head, int target);

#endif