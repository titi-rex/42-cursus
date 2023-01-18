/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:49:41 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/18 14:49:56 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief get the number of rotate needed for reach a value in range
 * 
 * @param stack stack to search in
 * @param min min range
 * @param max max range
 * @return int number of rotate needed // -1 if not possible
 */
int	ft_len_r(t_stack *stack, int min, int max)
{
	int	len;

	len = 0;
	while (stack && (stack->value > max || stack->value < min))
	{
		stack = stack->next;
		len++;
	}
	if (!stack)
		len = -1;
	return (len);
}

/**
 * @brief get the number of reverse rotate needed for reach a value in range
 * 
 * @param stack stack to search in
 * @param min min range
 * @param max max range
 * @return int int number of reverse rotate needed // -1 if not possible
 */
int	ft_len_rr(t_stack *stack, int min, int max)
{
	int	len;
	int	i;

	len = 0;
	i = ft_stacksize(stack);
	while (len < i && (stack->value > max || stack->value < min))
	{
		ft_rotate_reverse(&stack);
		len++;
	}
	if (len == i)
		return (-1);
	i = len;
	while (i > 0)
	{
		ft_rotate(&stack);
		i--;
	}
	return (len);
}

/**
 * @brief find the nearest element in desired range 
 * can be used in stack a or b thank to name param
 * 
 * @param start ptr to first element of stack
 * @param min min range
 * @param max max range
 * @param name stack indicator
 * @return int return value : 1 errorr // 0 ok
 */
int	ft_next(t_stack **start, int min, int max, char name)
{
	int	len;
	int	len_rr;

	len = ft_len_r(*start, min, max);
	len_rr = ft_len_rr(*start, min, max);
	if (len == -1 || len_rr == -1)
		return (-1);
	if (len <= len_rr)
	{
		if (name == 'a')
			ft_rotate_p(start, 'a', len);
		else
			ft_rotate_p(start, 'b', len);
	}
	else
	{
		if (name == 'a')
			ft_rotate_reverse_p(start, 'a', len_rr);
		else
			ft_rotate_reverse_p(start, 'b', len_rr);
	}
	return (0);
}
