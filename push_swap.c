/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:21:41 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/17 15:41:23 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_freesplit(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

int	ft_splitlen(char **split)
{
	int	len;

	len = 0;
	while (split[len])
		len++;
	return (len);
}

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
	int		pivot;
	int		len;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		stack_a = ft_create_stack(split, ft_splitlen(split), 0);
		ft_freesplit(split);
	}
	else
		stack_a = ft_create_stack(argv, argc, 1);
	if (!stack_a)
		return (1);
	len = ft_stacksize(stack_a);
	if (!ft_is_sorted(stack_a, 0, len))
		return (0);
	if (len > 250)
	{
		pivot = len / 2;
		ft_partition(&stack_a, 0, len, pivot);
	}
	ft_quicksort(&stack_a, len, len / 100 * 7 + 9);
	ft_stackclear(&stack_a);
	return (0);
}

// 3 aprtition
// w/out 	max : 7446	av : 6935
// w/ 		max : 7498	av : 6989

// 1 prt best perf pour > 250
