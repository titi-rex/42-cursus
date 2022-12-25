/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:20:01 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/25 15:59:16 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int	ft_solver2(t_stack **stack_a)
{
	t_stack			**stack_b = NULL;
	t_stack			*current;
	// unsigned int	size;
	int				i;
	int				n;
	int				tmp;

	size = ft_stacksize(&stack_a);
	current = *stack_a;
	i = 0;
	while (ft_is_sorted(stack_a))
	{
		tmp = (*stack_a)->value;
		ft_rotate(stack_a);
		ft_printf("ra\n");
		while ((*stack_a)->value != tmp)
		{
			ft_rotate(stack_a);
			ft_printf("ra\n");
			if ((*stack_a)->value < tmp)
			{
				ft_push(stack_a, stack_b);
				ft_printf("pb\n");
			}
		}
		while (*stack_b)
		{
			ft_push(stack_b, stack_a);
			ft_printf("pa\n");
		}
	}
	return (0);
}
*/