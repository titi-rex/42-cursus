/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:20:01 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/13 17:32:17 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	//			if (!ft_is_sorted(*stack_a))
	//			break ;
	//	ha<3

void	ft_insert_sort_b(t_stack **start_a, t_stack **start_b)
{
	if (!(*start_b) || (*start_a)->value > ft_stackmax(*start_b))
	{
		ft_push(start_a, start_b);
		ft_printf("pb\n");
		double_print(*start_a, *start_b);
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

void	ft_insert_sort_a(t_stack **start_a, t_stack **start_b, int pivot)
{
	int	n;
	int	i;

	if (!(*start_a) || (*start_b)->value < pivot)
	{
		ft_push(start_b, start_a);
		ft_printf("pa\n");
		double_print(*start_a, *start_b);
	}
	else
	{
		n = 1;
		i = 0;
		while ((*start_a)->value != pivot)
		{
			ft_rotate(start_a);
			ft_printf("ra\n");
			n++;
		}
		ft_rotate(start_a);
		ft_printf("ra\n");
		ft_push(start_b, start_a);
		ft_printf("pb\n");
		while (i < n)
		{
			ft_rotate_reverse(start_a);
			ft_printf("rra\n");
			i++;
		}
		double_print(*start_a, *start_b);
	}
}

int	ft_partition(t_stack **start_a, int start, int end)
{
	t_stack	*stack_b;
	t_stack	*current;
	int		pivot;
	int		tmp;
	int		i;
	int		wit;
	int		pivotvu;

	if (start >= end)
		return (-1);
	stack_b = NULL;
	i = 1;
	pivotvu = 0;
	pivot = start;
	tmp = (start + end) / 2 + 1;
	if (tmp == end)
		tmp--;
	ft_printf("start is %d\tend is %d\n", start, end);
	ft_printf("tmp is : %d\n", tmp);
	double_print(*start_a, stack_b);
	while (i != start)
	{
		ft_rotate(start_a);
		ft_printf("ra\n");
		i++;
	}
	while (i <= end)
	{
		if ((*start_a)->value < tmp)
		{
			if (start - end <= 11)
				ft_insert_sort_b(start_a, &stack_b);
			else
			{
				ft_push(start_a, &stack_b);
				ft_printf("pb\n");
				double_print(*start_a, stack_b);
			}
		}
		else if ((*start_a)->value == tmp)
		{
			pivotvu = 1;
			ft_rotate(start_a);
			ft_printf("ra\n");
			double_print(*start_a, stack_b);
		}
		else
		{
			if (pivotvu == 0)
				ft_insert_sort_b(start_a, &stack_b);
			else
			{
				ft_rotate(start_a);
				ft_printf("ra\n");
				double_print(*start_a, stack_b);
			}
		}
		i++;
	}
	while ((*start_a)->value != tmp)
	{
		ft_rotate(start_a);
		ft_printf("ra\n");
		double_print(*start_a, stack_b);
	}
	while (stack_b)
	{
		ft_insert_sort_a(start_a, &stack_b, tmp);
		double_print(*start_a, stack_b);
		pivot++;
	}
	i = 1;
	current = (*start_a);
	while (current->value != tmp)
	{
		i++;
		current = current->next;
	}
	ft_printf(" le i qa la con is %d\n", i);
	if (i != pivot)
	{
		wit = pivot - i;
		if (wit > 0)
		{
			while (wit > 0)
			{
				ft_rotate_reverse(start_a);
				ft_printf("rra\n");
				wit--;
			}
		}
		else
		{
			while (wit < 0)
			{
				ft_rotate(start_a);
				ft_printf("ra\n");
				wit++;
			}
		}
	}
	ft_printf("fin partition\n");
	ft_printf("posipvot found is %d\n", pivot);
	double_print(*start_a, stack_b);
	ft_stackclear(&stack_b);
	return (pivot);
}

void	ft_little_sort(t_stack **start_a, int start, int end)
{
	t_stack	*stack_b;
	int		i;

	i = 1;
	stack_b = NULL;
	while (i < start)
	{
		ft_rotate(start_a);
		ft_printf("ra\n");
		i++;
	}
	while (i <= end)
	{
		ft_insert_sort_b(start_a, &stack_b);
		i++;
	}
	while (stack_b)
	{
		ft_push(&stack_b, start_a);
		ft_printf("pa\n");
	}
	while ((*start_a)->value != ft_stackmax(*start_a))
	{
		ft_rotate(start_a);
		ft_printf("ra\n");
	}
	ft_rotate(start_a);
	ft_printf("ra\n");
}

int	ft_quicksort(t_stack **start_a, int start, int end)
{
	int	pivot;

	if (!ft_is_sorted(*start_a, start, end))
		return (0);
	if (start < end)
	{
		pivot = ft_partition(start_a, start, end);
		ft_quicksort(start_a, start, pivot - 1);
		if (end == ft_stackmax(*start_a) && end - (pivot + 1) <= 4)
			ft_little_sort(start_a, pivot + 1, end);
		else
			ft_quicksort(start_a, pivot + 1, end);
	}
	return (0);
}

int	ft_solverouin(t_stack **start_a)
{
	int	size;

	size = ft_stacksize(*start_a);
	ft_quicksort(start_a, 1, size);
	return (0);
}
