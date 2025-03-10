/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:55:25 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/14 12:37:38 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief check if arg is an int
 * 
 * @param arg string to verify
 * @return int error value (0 == OK // 1 == ERROR)
 */
int	ft_is_valid(char *arg)
{
	int			i;
	int			wit;
	long int	n;

	wit = 0;
	if (arg[wit] == '-')
		wit++;
	i = wit;
	if (!arg[i])
		return (1);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) || i > 9 + wit)
			return (1);
		i++;
	}
	n = ft_atol(arg);
	if (n > INT_MAX || n < INT_MIN)
		return (1);
	return (0);
}

/**
 * @brief display error depending on wit
 * 
 * @param wit indicate the type of error
 * @return int always 1 (error signal)
 */
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(3);
}

void	ft_clean_error(t_stack **stack, char **arg, int err_flag)
{
	ft_stackclear(stack);
	if (!err_flag)
		ft_freesplit(arg);
	ft_error();
}

/**
 * @brief check is the stack is sorted
 * 
 * @param stack stack to check
 * @return int 0 == sorted // 1 == not sorted
 */
int	ft_is_sorted(t_stack *stack, int start, int end)
{
	int	i;

	if (!stack)
		return (0);
	i = 1;
	while (i < start)
	{
		stack = stack->next;
		i++;
	}
	while (stack && stack->next && i <= end)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
		i++;
	}
	return (0);
}

/**
 * @brief give number of string in a split
 * 
 * @param split 
 * @return int 
 */
int	ft_splitlen(char **split)
{
	int	len;

	len = 0;
	while (split[len])
		len++;
	return (len);
}
