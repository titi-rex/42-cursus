/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:21:41 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/12 22:19:33 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	
	if (argc == 1 || argc == 2)
		return (0);
	stack_a = NULL;
	if (ft_create_stack(argv, argc, stack_a))
		return (ft_error(0));
	

	ft_stackclear(stack_a);
	return (0);
}

int	ft_is_valid(char *arg)
{
	int		i;
	long	n;

	i = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) || i > 9)
			return (1);
		i++;
	}
	n = ft_atoi(arg);
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
int	ft_error(int wit)
{
	if (!wit)
		write(1, "Error\n", 6);
	else if (wit == 1)
		write(1, "Malloc fail\n", 12);
	return (1);
}
