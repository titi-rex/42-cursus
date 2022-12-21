/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:21:41 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/21 15:32:26 by tlegrand         ###   ########.fr       */
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
	t_stack	*stack_b;
	t_stack	**start_a;
	t_stack	**start_b;

//	stack_a = NULL;
	stack_b = NULL;
	start_b = &stack_b;
	if (argc == 1 || argc == 2)
		return (0);
	stack_a = ft_create_stack(argv, argc);
	if (!stack_a)
		return (1);
	start_a = &stack_a;
	// ft_push(start_a, start_b);
	// ft_printf("pb: \n");
	// ft_printf("stack a : \n");
	// ft_print_stack(*start_a);
	// ft_printf("stack b : \n");
	ft_print_stack(*start_b);
//	ft_solver1(&stack_a);
//	ft_stackclear(&stack_a);
	ft_print_stack(*start_a);
	ft_rotate(start_a);
	ft_printf("ra\n");
	ft_print_stack(*start_a);
	return (0);
}
