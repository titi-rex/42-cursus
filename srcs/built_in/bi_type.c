/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:10:01 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/18 16:46:49 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_type(t_line	*line)
{
	//char	tmp;
	int		i;

	i = 1;
	while (line->cmd->arg[i])
	{
		if (line->cmd->arg[i][0] == '.' || line->cmd->arg[i][0] == '/')
		{
			if (!access(line->cmd->arg[i], X_OK))
			{
				printf("%s is %s\n", line->cmd->arg[i], line->cmd->arg[i]);
				return (EXIT_SUCCESS);
			}
			else
			{
				printf("%s not found\n", line->cmd->arg[i]);
				return (EXIT_FAILURE);
			}
		}
		if (ft_is_bi(line->cmd->arg[i]))
		{
			printf("%s is minishell built-in\n", line->cmd->arg[i]);
			return (EXIT_SUCCESS);
		}
		// else
		// {
		// 	if ()
		// }
		i++;
	}
	return (EXIT_FAILURE);
}
