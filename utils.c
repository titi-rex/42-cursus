/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:55:25 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/15 13:57:33 by tlegrand         ###   ########.fr       */
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
 * @brief print the stack
 * 
 * @param head first element of stack
 * @return int lenght writed
 */
int	ft_print_stack(t_stack *head)
{
	int		len;

	len = 0;
	while (head)
	{
		len += ft_printf("%d\n", head->value);
		head = head->next;
	}
	len += ft_printf("END\n");
	return (len);
}
