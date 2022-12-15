/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:20:01 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/15 19:01:58 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_solver2(t_stack **stack_a)
{
	t_stack			**stack_b;
	t_stack			*current;
	unsigned int	size;
	int				i;

	size = ft_stacksize(&stack_a);
	current = *stack_a;
	i = 0;
	while (ft_is_sorted(stack_a))
	{
		while (current)
		{
			if ((current->value % 10) == i)
			{
				ft_printf("pb\n");
				ft_push(&current, stack_b);
			}
			current = current->next;
			ft_printf("ra\n");
		}
		while (iii)
		i++;
	}
	return (0);
}
