/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:24:00 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/12 22:35:37 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief create a new t_stack with value
 * 
 * @param value value of new t_stack
 * @return t_stack* ptr to new t_stack / NULL if malloc error
 */
t_stack	*ft_stacknew(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

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
 * @brief add a new t_stack at last element of a stack
 * 
 * @param head ptr to first element of the stack
 * @param new t_stack to add
 */
void	ft_stackadd_back(t_stack **head, t_stack *new)
{
	if (!head || !new)
		return ;
	if (!*head)
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

/**
 * @brief search the first element with specified value in a stack
 * 
 * @param head ptr to first element of stack
 * @param value value to look for
 * @return t_stack* ptr to first element with value // NULL if none
 */
t_stack	*ft_stacksearch(t_stack **head, int value)
{
	if (!head)
		return (NULL);
	while (*head && (*head)->value != value)
		(*head) = (*head)->next;
	return (*head);
}

/**
 * @brief create a stack with a 2d aray of char
 * 
 * @param arg 2d array of char contening value for stack
 * @param n_arg number of arg 
 * @param stack ptr to first element of the stack
 * @return int error value (0 == OK // 1 == ERROR)
 */
int	ft_create_stack(char **arg, int n_arg, t_stack **stack)
{
	int		i;
	t_stack	*new;

	i = 1;
	while (i <= n_arg)
	{
		if (ft_is_valid(arg[i]) || ft_stacksearch(stack, ft_atoi(arg[i])))
		{
			ft_stackclear(stack);
			return (ft_error(0));
		}
		new = ft_stacknew(ft_atoi(arg[i]));
		if (!new)
		{
			ft_stackclear(stack);
			return (ft_error(1));
		}
		ft_stackadd_back(stack, new);
	}
	i++;
	return (0);
}