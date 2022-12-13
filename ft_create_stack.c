/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:24:00 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/13 13:50:26 by tlegrand         ###   ########.fr       */
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
 * @brief create a stack with a 2d aray of char
 * 
 * @param arg 2d array of char contening value for stack
 * @param n_arg number of arg 
 * @param stack ptr to first element of the stack
 * @return int error value (0 == OK // 1 == ERROR)
 */
t_stack	*ft_create_stack(char **arg, int n_arg)
{
	int		i;
	t_stack	*new;
	t_stack	*start;

	i = 1;
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
