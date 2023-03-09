/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:27:20 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/09 14:37:36 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	bi_count_arg(char **arg)
{
	int	n;

	n = 0;
	while (arg[n])
		n++;
	return (n);
}

/*	TODO: cd $HOME	*/
/*	TODO: update env after cd	*/
int	bi_cd(t_line *line)
{
	if (bi_count_arg(line->cmd->arg) > 2)
	{
		ft_putstr_fd("Error, too much arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (!line->cmd->arg[1])
	{
		chdir("");
		perror("Error ");
		return (EXIT_SUCCESS);
	}
	if (!chdir(line->cmd->arg[1]))
		return (EXIT_SUCCESS);
	perror("Error ");
	return (EXIT_FAILURE);
}
