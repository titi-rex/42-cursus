/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:28:08 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/13 17:42:28 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_solver(t_stack **start_a)
{
	t_stack	*stack_b;
	
	ft_quicksort(start_a, ft_stackmax(*start_a));
	return (0);
}

void	ft_quicksort(t_stack **start_a, int len)
{
	int	pivot;
	int	chunk;

	chunk = 1;
	pivot = len / 4 * chunk;
	if (pivot >= len)
		return ;
	while  
}
