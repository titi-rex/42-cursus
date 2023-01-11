/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:20:01 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/11 18:56:12 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* passage aux indices -> tmp choisi par division 
faire fonction search chemin 
faire plusieurs passage d un cou p
*/
/*
t_stack	*ft_create_border(int size)
{
	t_stack	*new;
	t_stack *start;
	int		tmp;
	int		i;

	new = ft_stacknew(size);
	if (!new)
		return (ft_error(ft_error(1)));
	ft_stackadd_front(&start, new);
	while (i > size /10)
	{
		
	}
	return (start);
}

int	ft_solver2(t_stack **stack_a)
{
	t_stack			**stack_b;
	t_stack			*start_b;
	t_stack			*border;
	t_stack			*tmplst;
	int				tmp;
	int				tour;

	tour = 0;
	start_b = NULL;
	border = NULL;
	tmplst = NULL;
	stack_b = &start_b;
	tmp = 0;
	ft_stackadd_front(&border, ft_stacknew(ft_stacklast(*stack_a)->value));
	while (ft_is_sorted(*stack_a) && tour < 10)
	{
		tmp = ft_find_pivot(tmplst, *stack_a);
		printf("tmp is : %d\n", tmp);
		printf("border is : %d\n", border->value);
		while ((*stack_a)->value != border->value)
		{
			if ((*stack_a)->value < tmp)
			{
				ft_push(stack_a, stack_b);
				ft_printf("pb\n");
				double_print(*stack_a, *stack_b);
			}
			else
			{
				ft_rotate(stack_a);
				ft_printf("ra\n");
				double_print(*stack_a, *stack_b);
			}
		}
		if ((*stack_a)->value < tmp)
		{
			ft_push(stack_a, stack_b);
			ft_printf("pb\n");
			double_print(*stack_a, *stack_b);
		}
		printf("2 nd etape \n");
		while ((*stack_a)->value != tmp)
		{
			ft_rotate(stack_a);
			ft_printf("ra\n");
			double_print(*stack_a, *stack_b);
		}
		while (*stack_b)
		{
			ft_push(stack_b, stack_a);
			ft_printf("pa\n");
			double_print(*stack_a, *stack_b);
		}
		tour++;
		ft_stackadd_front(&border, ft_stacknew(tmp));

	}
	printf("nbr tour : %d\n", tour);
	return (0);
}*/

	//		printf("curr : %d\ttmp : %d\n", (*stack_a)->value, tmp[i]);
	//	printf("2 nd etape \n");

	//			if (!ft_is_sorted(*stack_a))
	//			break ;
	//	ha<3

int	ft_partition(t_stack **start_a, int start, int end)
{
	t_stack	*stack_b;
	t_stack	*current;
	int		pivot;
	int		tmp;
	int		i;
	int		wit;

	if (start >= end)
		return (-1);
	stack_b = NULL;
	i = 1;
	pivot = start;
	tmp = (start + end) / 2 + 1;
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
			ft_push(start_a, &stack_b);
			ft_printf("pb\n");
			double_print(*start_a, stack_b);
		}
		else
		{
			ft_rotate(start_a);
			ft_printf("ra\n");
			double_print(*start_a, stack_b);
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
		ft_push(&stack_b, start_a);
		ft_printf("pa\n");
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
	return (pivot);
}

int	ft_quicksort(t_stack **start_a, int start, int end)
{
	int	pivot;

	if (!ft_is_sorted(*start_a))
		return (0);
	if (start < end)
	{
		pivot = ft_partition(start_a, start, end);
		ft_quicksort(start_a, start, pivot - 1);
		ft_quicksort(start_a, pivot + 1, end);
	}
	return (0);
}

int	ft_solver2(t_stack **start_a)
{
	int	size;

	size = ft_stacksize(*start_a);
	ft_quicksort(start_a, 1, size);
	return (0);
}
