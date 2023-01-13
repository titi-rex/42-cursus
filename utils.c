/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:55:25 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/13 14:49:49 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!ft_isdigit(arg[wit]))
		return (1);
	i = wit;
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
void	*ft_error(int wit)
{
	if (!wit)
		write(1, "Error\n", 6);
	else if (wit == 1)
		write(1, "Malloc fail\n", 12);
	return (NULL);
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
 * @brief function swapping the value of two first element of a stack
 * 
 * @param head first element of stack
 */
void	ft_swap_value(t_stack *head)
{
	int	tmp;

	if (!head || !(head->next) || !(head->next->next))
		return ;
	tmp = head->value;
	head->value = head->next->value;
	head->next->value = tmp;
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
		printf("\n");
	}
}

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
