/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smol_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:00:21 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/18 14:38:23 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_smol_three(t_stack **stack)
{
	if ((*stack)->value < (*stack)->next->value)
	{
		if ((*stack)->value < (*stack)->next->next->value)
		{
			ft_swap_p(stack, 'a');
			ft_rotate_p(stack, 'a', 1);
		}
		else
			ft_rotate_reverse_p(stack, 'a', 1);
	}
	else
	{
		if ((*stack)->value < (*stack)->next->next->value)
			ft_swap_p(stack, 'a');
		else
		{
			if ((*stack)->next->value < (*stack)->next->next->value)
				ft_rotate_p(stack, 'a', 1);
			else
			{
				ft_swap_p(stack, 'a');
				ft_rotate_reverse_p(stack, 'a', 1);
			}
		}
	}
}

void	ft_smol_five(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	ft_next(stack_a, ft_stackmin(*stack_a), ft_stackmin(*stack_a), 'a');
	ft_push_p(stack_a, &stack_b, 'b', 1);
	ft_next(stack_a, ft_stackmin(*stack_a), ft_stackmin(*stack_a), 'a');
	ft_push_p(stack_a, &stack_b, 'b', 1);
	if (ft_is_sorted(*stack_a, 0, 3))
		ft_smol_three(stack_a);
	ft_push_p(&stack_b, stack_a, 'a', 1);
	ft_push_p(&stack_b, stack_a, 'a', 1);
}

void	ft_smol_sort(t_stack **stack, int len)
{
	if (len == 2)
		ft_swap_p(stack, 'a');
	else if (len == 3)
		ft_smol_three(stack);
	else
		ft_smol_five(stack);
}
