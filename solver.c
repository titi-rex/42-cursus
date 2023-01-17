/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:28:08 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/17 16:14:44 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief get the number of rotate needed for reach a value in range
 * 
 * @param stack stack to search in
 * @param min min range
 * @param max max range
 * @return int number of rotate needed // -1 if not possible
 */
int	ft_len_r(t_stack *stack, int min, int max)
{
	int	len;

	len = 0;
	while (stack && (stack->value > max || stack->value < min))
	{
		stack = stack->next;
		len++;
	}
	if (!stack)
		len = -1;
	return (len);
}

/**
 * @brief get the number of reverse rotate needed for reach a value in range
 * 
 * @param stack stack to search in
 * @param min min range
 * @param max max range
 * @return int int number of reverse rotate needed // -1 if not possible
 */
int	ft_len_rr(t_stack *stack, int min, int max)
{
	int	len;
	int	i;

	len = 0;
	i = ft_stacksize(stack);
	while (len < i && (stack->value > max || stack->value < min))
	{
		ft_rotate_reverse(&stack);
		len++;
	}
	if (len == i)
		return (-1);
	i = len;
	while (i > 0)
	{
		ft_rotate(&stack);
		i--;
	}
	return (len);
}

/**
 * @brief find the nearest element in desired range 
 * can be used in stack a or b thank to name param
 * 
 * @param start ptr to first element of stack
 * @param min min range
 * @param max max range
 * @param name stack indicator
 * @return int return value : 1 errorr // 0 ok
 */
int	ft_next(t_stack **start, int min, int max, char name)
{
	int	len;
	int	len_rr;

	len = ft_len_r(*start, min, max);
	len_rr = ft_len_rr(*start, min, max);
	if (len == -1 || len_rr == -1)
		return (-1);
	if (len <= len_rr)
	{
		if (name == 'a')
			ft_rotate_p(start, 'a', len);
		else
			ft_rotate_p(start, 'b', len);
	}
	else
	{
		if (name == 'a')
			ft_rotate_reverse_p(start, 'a', len_rr);
		else
			ft_rotate_reverse_p(start, 'b', len_rr);
	}
	return (0);
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
void	ft_insert_sort(t_stack **start_src, char name_src, t_stack **start_dst)
{
	int	target;

	if (name_src == 'a')
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
 * @brief insert_sort algo by rotating dst
 * search optimal position for top src value in dst stack
 * only use from a to b
 * 
 * @param start_a ptr to a stack
 * @param start_b ptr to b stack
 */
void	ft_insert_sort_dst(t_stack **start_a, t_stack **start_b)
{
	if (!(*start_b) || (*start_a)->value > (*start_b)->value)
		ft_push_p(start_a, start_b, 'b', 1);
	else if ((*start_a)->value < ft_stackmin(*start_b))
	{
		ft_push_p(start_a, start_b, 'b', 1);
		ft_rotate_p(start_b, 'b',  1);
	}
	else
	{
		while ((*start_a)->value < (*start_b)->value)
			ft_rotate_p(start_b, 'b', 1);
		ft_push_p(start_a, start_b, 'b', 1);
	}
	ft_next(start_b, ft_stackmax(*start_b), ft_stackmax(*start_b), 'b');
}
