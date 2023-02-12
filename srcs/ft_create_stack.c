/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:24:00 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/12 19:43:29 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
 * @brief create stack and check is arg are legit on the go
 * if error occur, display error message and quit
 * 
 * @param arg arg to build stack from
 * @param n_arg number of arg
 * @param idx_start where to start from arg (used if arg[0] is program's name)
 * @return t_stack* ptr to first element of stack
 */
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
			ft_error();
		}
		new = ft_stacknew(ft_atoi(arg[i]));
		if (!new)
		{
			ft_stackclear(&start);
			ft_error();
		}
		ft_stackadd_back(&start, new);
		i++;
	}
	return (start);
}

/**
 * @brief  find desired index from a value
 * 
 * @param target value to convert in index
 * @param stack 
 * @return int index value
 */
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

/**
 * @brief create a new stack with index keeping order
 * 
 * @param stack stack to build new stack from
 * @return t_stack* ptr to stack created
 */
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
			ft_error();
		}
		ft_stackadd_back(&start, new);
		current = current->next;
	}
	return (start);
}

/**
 * @brief create stack, check for error, and remplace stack value with index
 * if error occur, display error message and quit
 * 
 * @param arg arg to build stack from
 * @param n_arg number of arg
 * @param start where to start from arg (used if arg[0] is program's name)
 * @return t_stack* ptr to first element of stack
 */
t_stack	*ft_create_stack(char **arg, int n_arg, int start)
{
	t_stack	*stack;
	t_stack	*stack_tmp;

	stack_tmp = ft_init_stack(arg, n_arg, start);
	if (stack_tmp)
	{
		stack = ft_index(stack_tmp);
		ft_stackclear(&stack_tmp);
	}
	else
		ft_error();
	return (stack);
}
