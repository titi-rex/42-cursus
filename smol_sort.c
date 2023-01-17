/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smol_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:00:21 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/17 16:11:07 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_smol_three(t_stack *stack)
{
	if (stack->value < stack->next->value)
	{
		if (stack->value < stack->next->next->value)
		{
			ft_swap_p(&stack, 'a');
			ft_rotate_p(&stack, 'a', 1);
		}
		else
			ft_rotate_reverse_p(&stack, 'a', 1);
	}
	else
	{
		if (stack->value < stack->next->next->value)
			ft_swap_p(&stack, 'a');
		else
		{
			if (stack->next->value < stack->next->next->value)
				ft_rotate_p(&stack, 'a', 1);
			else
			{
				ft_swap_p(&stack, 'a');
				ft_rotate_reverse_p(&stack, 'a', 1);
			}
		}
	}
}
