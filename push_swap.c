/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:21:41 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/12 23:27:47 by tlegrand         ###   ########.fr       */
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

	printf("argc %d\n", argc);
	if (argc == 1 || argc == 2)
		return (0);
	stack_a = NULL;
	if (ft_create_stack(argv, argc, stack_a))
		return (ft_error(0));
	printf("value : %d\n", (*stack_a)->value);
	while (*stack_a)
	{
		printf("test\n");
		printf("value : %d\n", (*stack_a)->value);
		*stack_a = (*stack_a)->next;
	}
	ft_stackclear(stack_a);
	return (0);
}
