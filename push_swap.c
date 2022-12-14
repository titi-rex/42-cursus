/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:21:41 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/14 18:37:19 by tlegrand         ###   ########.fr       */
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
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc == 1 || argc == 2)
		return (0);
	stack_a = ft_create_stack(argv, argc);
	if (!stack_a)
		return (1);
//	ft_print_stack(stack_a);
	ft_solver1(stack_a);
	// ft_stackclear(&stack_a);
	return (0);
}
