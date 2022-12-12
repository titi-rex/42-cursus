/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:22:41 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/12 22:22:21 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
} t_stack;

void	ft_stackadd_back(t_stack **head, t_stack *new);
void	ft_stackclear(t_stack **head);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stacknew(int value);
int		ft_create_stack(char **arg, int n_arg, t_stack **stack);
t_stack	*ft_stacksearch(t_stack **head, int value);

int	ft_error(int wit);
int	ft_is_valid(char *arg);


#endif