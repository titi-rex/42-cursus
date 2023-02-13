/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:21:41 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/13 17:07:41 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// remplacer  directement dst par start dst etc a la fin
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
	char	**split;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			ft_error();
		stack_a = ft_create_stack(split, ft_splitlen(split), 0);
		ft_freesplit(split);
	}
	else
		stack_a = ft_create_stack(argv, argc, 1);
	if (!stack_a)
		return (0);
	ft_solver(&stack_a, ft_stacksize(stack_a));
	ft_stackclear(&stack_a);
	return (0);
}
