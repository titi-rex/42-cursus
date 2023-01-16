/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operator_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:46:54 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/16 17:49:27 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **start, int n)
{
	while (n > 0)
	{
		ft_rotate(start);
		ft_printf("ra\n");
		n--;
	}
}

void	ft_rb(t_stack **start, int n)
{
	while (n > 0)
	{
		ft_rotate(start);
		ft_printf("rb\n");
		n--;
	}
}

void	ft_rra(t_stack **start, int n)
{
	while (n > 0)
	{
		ft_rotate_reverse(start);
		ft_printf("rra\n");
		n--;
	}
}

void	ft_rrb(t_stack **start, int n)
{
	while (n > 0)
	{
		ft_rotate_reverse(start);
		ft_printf("rrb\n");
		n--;
	}
}
