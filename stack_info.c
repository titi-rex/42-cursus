/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:47:18 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/20 23:07:28 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
 * @brief get the maximum value stored in stack
 * 
 * @param stack 
 * @return int max
 */
int	ft_stackmax(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

/**
 * @brief get the minimum value stored in stack
 * 
 * @param stack 
 * @return int min
 */
int	ft_stackmin(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

/**
 * @brief search the first element with specified value in a stack
 * 
 * @param head ptr to first element of stack
 * @param value value to look for
 * @return t_stack* ptr to first element with value // NULL if none
 */
t_stack	*ft_stacksearch(t_stack *head, int value)
{
	while (head && head->value != value)
		head = head->next;
	return (head);
}
