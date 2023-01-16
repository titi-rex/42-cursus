/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:28:08 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/16 19:01:13 by tlegrand         ###   ########.fr       */
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
			ft_rra(start, len_rr);
		else
			ft_rrb(start, len_rr);
	}
	return (0);
}

void	ft_insert_sort(t_stack **start_src, char name_src, t_stack **start_dst)
{
	int	target;

	if (name_src == 'a')
	{
		target = ft_stackmin(*start_src);
		ft_next(start_src, target, target, 'a');
		ft_push_p(start_src, start_dst, 1, 'b');
	}
	else
	{
		target = ft_stackmax(*start_src);
		ft_next(start_src, target, target, 'b');
		ft_push_p(start_src, start_dst, 1, 'a');
	}
}

void	ft_insert_sort_dst(t_stack **start_a, t_stack **start_b)
{
	if (!(*start_b) || (*start_a)->value > ft_stackmax(*start_b))
		ft_push_p(start_a, start_b, 1, 'b');
	else if ((*start_a)->value < ft_stackmin(*start_b))
	{
		ft_push_p(start_a, start_b, 1, 'b');
		ft_rb(start_b, 1);
	}
	else
	{
		ft_next(start_b, (*start_a)->value - 1, (*start_a)->value - 1, 'b');
		ft_push_p(start_a, start_b, 1, 'b');
	}
}

void	ft_quicksort(t_stack **start_a, int len)
{
	t_stack	*stack_b;
	int		pivot;
	int		count;
	int		chunk;

	count = 0;
	stack_b = NULL;
	chunk = len / 100 * 7 + 13;
	pivot = chunk;
	while (*start_a)
	{
		if (count == pivot)
			pivot += chunk;
		if (pivot >= len - chunk)
			ft_insert_sort(start_a, 'a', &stack_b);
		else if (pivot <= chunk)
		{
			ft_next(start_a, pivot - chunk, pivot, 'a');
			ft_insert_sort_dst(start_a, &stack_b);
		}
		else
		{
			ft_next(start_a, pivot - chunk, pivot, 'a');
			ft_push_p(start_a, &stack_b, 1, 'b');
		}
		count++;
	}
	while (stack_b)
		ft_insert_sort(&stack_b, 'b', start_a);
}

void	ft_insert_sort_a(t_stack **start_src, t_stack **start_dst)
{
	int	target;

	target = ft_stackmax(*start_src);
	ft_next(start_src, target, target, 'b');
	ft_push_p(start_src, start_dst, 1, 'a');
}

void	ft_insert_sort_b(t_stack **start_a, t_stack **start_b)
{
	if (!(*start_b) || (*start_a)->value > ft_stackmax(*start_b))
	{
		ft_push(start_a, start_b);
		ft_printf("pb\n");
	}
	else if ((*start_a)->value < ft_stackmin(*start_b))
	{
		ft_push(start_a, start_b);
		ft_printf("pb\n");
		ft_rotate(start_b);
		ft_printf("rb\n");
		double_print(*start_a, *start_b);
	}
	else
	{
		while ((*start_b)->value > (*start_a)->value)
		{
			ft_rotate(start_b);
			ft_printf("rb\n");
		}
		ft_push(start_a, start_b);
		ft_printf("pb\n");
		while ((*start_b)->value != ft_stackmax(*start_b))
		{
			ft_rotate(start_b);
			ft_printf("rb\n");
		}
		double_print(*start_a, *start_b);
	}
}