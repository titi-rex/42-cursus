/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:28:08 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/16 17:50:40 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			ft_ra(start, len);
		else
			ft_rb(start, len);
	}
	else
	{
		if (name == 'a')
			ft_rra(start, len);
		else
			ft_rrb(start, len);
	}
	return (0);
}

void	ft_insert_sort(t_stack **start_src, t_stack **start_dst)
{
	int	target;

	target = ft_stackmax(*start_src);
	ft_next(start_src, target, target, 'b');
	ft_push(start_src, start_dst);
	ft_printf("pa\n");
}

void	ft_quicksort(t_stack **start_a, int len)
{
	t_stack	*stack_b;
	int		pivot;
	int		count;
	int		chunk;

	count = 0;
	stack_b = NULL;
	chunk = len / 4;
	pivot = chunk;
	while (*start_a)
	{
		if (count == pivot)
			pivot += chunk;
		ft_next(start_a, pivot - chunk, pivot, 'a');
		ft_push(start_a, &stack_b);
		ft_printf("pb\n");
		count++;
	}
	while (stack_b)
		ft_insert_sort(&stack_b, start_a);
//	double_print(*start_a, stack_b);
//	ft_printf("end quicksort\n");
}
