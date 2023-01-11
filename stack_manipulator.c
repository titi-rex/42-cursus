/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:48:15 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/09 17:33:58 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief find the last t_stack
 * 
 * @param stack firts element of the stack
 * @return t_stack* last t_stack of the stack
 */
t_stack	*ft_stacklast(t_stack *stack)
{
	if (stack)
	{
		while (stack->next)
			stack = stack->next;
	}
	return (stack);
}

/**
 * @brief simple function searching penultimate element
 * 
 * @param head first element of the stack 
 * @return t_stack* ptr to penutimate element
 */
t_stack	*ft_stack_penultimate(t_stack *head)
{
	if (head && head->next)
	{
		while (head->next->next)
			head = head->next;
	}
	return (head);
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

/**
 * @brief add a new t_stack at last element of a stack
 * 
 * @param head ptr to first element of the stack
 * @param new t_stack to add
 */
void	ft_stackadd_back(t_stack **head, t_stack *new)
{
	if (!head || !new)
		return ;
	else if (!*head)
		*head = new;
	else
		ft_stacklast(*head)->next = new;
}

/**
 * @brief clear and free the stack
 * 
 * @param head ptr to first element of the stack
 */
void	ft_stackclear(t_stack **head)
{
	t_stack	*buff;

	if (!head)
		return ;
	while (*head)
	{
		buff = (*head)->next;
		(*head)->value = 0;
		free(*head);
		*head = buff;
	}
	head = NULL;
}

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
