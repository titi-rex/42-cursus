/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:21:41 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/12 22:55:55 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief main function, call others functions
 * 
 * @param argc number of argv
 * @param argv arg
 * @return int error value (0 == OK // 1 == ERROR)
 */
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
