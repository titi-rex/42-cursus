/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:19:36 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/15 18:24:49 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	print_deg(t_stack *head, int len)
{
	while (len > 0)
	{
		printf("%d\n", head->value);
		head = head->next;
		len--;
	}
}

int	ft_solver1(t_stack **stack_a)
{
	int		min;
	int		size;
	int		i;

	size = ft_stacksize(*stack_a);
	i = size;
	ft_stacklast(*stack_a)->next = *stack_a;
	while (i > 0)
	{
		min = ft_searchmin(*stack_a, i);
		while ((*stack_a)->value != min)
		{
			ft_printf("ra\n");
			*stack_a = (*stack_a)->next;
		}
		ft_printf("pb\n");
		ft_stackdel(stack_a, min);
		*stack_a = (*stack_a)->next;
		i--;
	}
	while (size > 0)
	{
		ft_printf("pa\n");
		size--;
	}
	return (0);
}

/**
 * @brief count size of stack
 * 
 * @param head firts element of stack
 * @return int size of stack
 */
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

/**
 * @brief search for minimum value stored in looped stack 
 * 
 * @param head first element of stack
 * @param size size of stack
 * @return int minimum value stored in stack
 */
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

/**
 * @brief delete element storing target value inside stack
 * preserve stack integrity
 * 
 * @param head first element of stack
 * @param target value to delete
 */
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
