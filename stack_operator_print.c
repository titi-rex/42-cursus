/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operator_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:46:54 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/17 16:10:10 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
