/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:28:08 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/18 14:45:27 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_partition(t_stack **start_a, int start, int end, int pivot)
{
	t_stack	*stack_b;
	int		count;

	if (start >= end)
		return ;
	stack_b = NULL;
	count = 0;
	if (start <= ft_stacksize(*start_a))
	{
		while (count != start)
		{
			ft_rotate_p(start_a, 'a', 1);
			count++;
		}
	}
	while (count < end)
	{
		if ((*start_a)->value >= pivot)
			ft_push_p(start_a, &stack_b, 'b', 1);
		else
			ft_rotate_p(start_a, 'a', 1);
		count++;
	}
	while (stack_b)
		ft_push_p(&stack_b, start_a, 'a', 1);
}

/**
 * @brief insert_sort algo by rotating src.
 * search for desired value in src and push it to dst
 * can be used to pa or pb thank to name param
 * 
 * @param start_src ptr to src stack
 * @param name_src name of src stack
 * @param start_dst ptr to dst stack
 */
void	ft_insert_sort(t_stack **start_src, char name, t_stack **start_dst)
{
	int	target;

	if (name == 'a')
	{
		target = ft_stackmin(*start_src);
		ft_next(start_src, target, target, 'a');
		ft_push_p(start_src, start_dst, 'b', 1);
	}
	else
	{
		target = ft_stackmax(*start_src);
		ft_next(start_src, target, target, 'b');
		ft_push_p(start_src, start_dst, 'a', 1);
	}
}

/**
 * @brief quicksort algo
 * push all value inside current chunk from a to b then again wit a new chunk
 * insert_sort for 1rst and last chunk
 * when a is empty, push back from b to a using insert_sort
 * 
 * @param start_a ptr to stack a
 * @param len size of stack a
 */
void	ft_quicksort(t_stack **start_a, int len, int chunk)
{
	t_stack	*stack_b;
	int		pivot;
	int		count;

	count = 0;
	stack_b = NULL;
	pivot = chunk;
	while (*start_a)
	{
		if (count == pivot)
			pivot += chunk;
		if (pivot >= len - chunk)
			ft_insert_sort(start_a, 'a', &stack_b);
		else
		{
			ft_next(start_a, pivot - chunk, pivot, 'a');
			ft_push_p(start_a, &stack_b, 'b', 1);
		}
		count++;
	}
	while (stack_b)
		ft_insert_sort(&stack_b, 'b', start_a);
}

void	ft_solver(t_stack **stack_a, int len)
{
	int	pivot;

	if (!ft_is_sorted(*stack_a, 0, len))
		return ;
	if (len <= 5)
	{
		ft_smol_sort(stack_a, len);
		return ;
	}
	if (len > 250)
	{
		pivot = len / 2;
		ft_partition(stack_a, 0, len, pivot);
	}
	ft_quicksort(stack_a, len, len / 100 * 7 + 9);
}
