/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:40:31 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/18 16:15:47 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief print the stack
 * 
 * @param head first element of stack
 * @return int lenght writed
 */
int	ft_print_stack(t_stack *head)
{
	int		len;

	len = 0;
	if (!head)
	{
		len += ft_printf("(null)\n", head);
	}
	while (head)
	{
		len += ft_printf("%d\n", head->value);
		head = head->next;
	}
	len += ft_printf("END\n");
	return (len);
}

/**
 * @brief print two stack side by side, even if one stack is empty
 * 
 * @param a stack a
 * @param b stack b
 */
void	double_print(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (a)
		{
			ft_printf("|%d|\t\t", a->value);
			a = a->next;
		}
		else
			ft_printf("|end|\t\t");
		if (b)
		{
			ft_printf("|%d|\t\t", b->value);
			b = b->next;
		}
		else
			ft_printf("|end|\t\t");
		ft_printf("\n");
	}
}
