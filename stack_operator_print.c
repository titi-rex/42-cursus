/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operator_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:46:54 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/20 23:15:31 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief use ft_swap and print instruction depending on name
 * 
 * @param stack stack to swap
 * @param name name of swap ('a' or 'b')
 */
void	ft_swap_p(t_stack **stack, char name)
{
	if (name == 'a')
	{
		ft_swap(stack);
		write(1, "sa\n", 3);
	}
	else
	{
		ft_swap(stack);
		write(1, "sb\n", 3);
	}
}

/**
 * @brief use ft_push and print instruction depending on name
 * 
 * @param start_src stack to push from
 * @param start_dst stack to push to
 * @param name name of push ('a' or 'b')
 * @param n number of push to do
 */
void	ft_push_p(t_stack **start_src, t_stack **start_dst, char name, int n)
{
	if (name == 'a')
	{
		while (n > 0)
		{
			ft_push(start_src, start_dst);
			ft_printf("pa\n");
			n--;
		}
	}
	if (name == 'b')
	{
		while (n > 0)
		{
			ft_push(start_src, start_dst);
			ft_printf("pb\n");
			n--;
		}
	}
}

/**
 * @brief use ft_rotate and print instruction depending on name
 * 
 * @param start stack to rotate
 * @param name name of rotate ('a' or 'b')
 * @param n number of rotate to do
 */
void	ft_rotate_p(t_stack **start, char name, int n)
{
	if (name == 'a')
	{
		while (n > 0)
		{
			ft_rotate(start);
			ft_printf("ra\n");
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			ft_rotate(start);
			ft_printf("rb\n");
			n--;
		}
	}
}

/**
 * @brief use ft_rotate_reverse and print instruction depending on name
 * 
 * @param start stack to rotate_reverse
 * @param name ame of rotate_reverse ('a' or 'b')
 * @param n number of rotate_reverse to do
 */
void	ft_rotate_reverse_p(t_stack **start, char name, int n)
{
	if (name == 'a')
	{
		while (n > 0)
		{
			ft_rotate_reverse(start);
			ft_printf("rra\n");
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			ft_rotate_reverse(start);
			ft_printf("rrb\n");
			n--;
		}
	}
}
