/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:21:41 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/13 15:17:13 by tlegrand         ###   ########.fr       */
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
	t_stack	**start_a;

	if (argc == 1 || argc == 2)
		return (0);
	stack_a = ft_create_stack(argv, argc);
	if (!stack_a)
		return (1);
	start_a = &stack_a;
	ft_print_stack(*start_a);
	ft_solver2(start_a);
	ft_print_stack(*start_a);
	ft_stackclear(&stack_a);
	return (0);
}
