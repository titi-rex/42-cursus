/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:24:00 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/17 15:31:15 by tlegrand         ###   ########.fr       */
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

t_stack	*ft_init_stack(char **arg, int n_arg, int idx_start)
{
	t_stack	*new;
	t_stack	*start;
	int		i;

	i = idx_start;
	new = NULL;
	start = new;
	while (i < n_arg)
	{
		if (ft_is_valid(arg[i]) || ft_stacksearch(start, ft_atoi(arg[i])))
		{
			ft_stackclear(&start);
			return (ft_error(0));
		}
		new = ft_stacknew(ft_atoi(arg[i]));
		if (!new)
		{
			ft_stackclear(&start);
			return (ft_error(1));
		}
		ft_stackadd_back(&start, new);
		i++;
	}
	return (start);
}

int	ft_findex(int target, t_stack *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		if (stack->value < target)
			i++;
		stack = stack->next;
	}
	return (i);
}

t_stack	*ft_index(t_stack *stack)
{
	t_stack	*start;
	t_stack	*new;
	t_stack	*current;

	current = stack;
	new = NULL;
	start = new;
	while (current)
	{
		new = ft_stacknew(ft_findex(current->value, stack));
		if (!new)
		{
			ft_stackclear(&start);
			return (ft_error(1));
		}
		ft_stackadd_back(&start, new);
		current = current->next;
	}
	return (start);
}

t_stack	*ft_create_stack(char **arg, int n_arg, int start)
{
	t_stack	*stack;
	t_stack	*stack_tmp;

	stack_tmp = ft_init_stack(arg, n_arg, start);
	stack = ft_index(stack_tmp);
	ft_stackclear(&stack_tmp);
	return (stack);
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (stack)
	{
		if (*stack)
			new->next = *stack;
		*stack = new;
	}
}
