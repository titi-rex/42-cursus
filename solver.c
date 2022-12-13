/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:52:47 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/13 17:52:29 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_deg(t_stack *head, int len)
{
	while (len>0)
	{
		printf("%d\n", head->value);
		head = head->next;
		len--;
	}
}

int	ft_solver1(t_stack *stack_a)
{
	int		min;
	int		size;
	t_stack	**start;

	start = &stack_a;
	size = ft_stacksize(stack_a);
	ft_stacklast(stack_a)->next = stack_a;
	while (size > 0)
	{
		min = ft_searchmin(stack_a, size);
		// printf("stack : %p\tvalue : %d\n", stack_a, stack_a->value);
		while (stack_a->value != min)
		{
			ft_printf("ra\n");
			stack_a = stack_a->next;
		}
		ft_printf("pb\n");
		ft_stackdel(start, min);
		stack_a = stack_a->next;
		size--;
	}
	return (0);
}

int	ft_stacksize(t_stack *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

int	ft_searchmin(t_stack *head, int size)
{
	int	min;

	min = head->value;
	while (size > 0)
	{
		if (head->value < min)
			min = head->value;
		head = head->next;
		size--;
	}
	return (min);
}

void	ft_stackdel(t_stack **head, int target)
{
	t_stack	*tmp;

	while ((*head)->next->value != target)
		*head = (*head)->next;
	tmp = (*head)->next->next;
	(*head)->next->value = 0;
	free((*head)->next);
	(*head)->next = tmp;
}