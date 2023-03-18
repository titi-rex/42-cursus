/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:10:01 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/18 20:32:20 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_type(t_line	*line)
{
	char	*tmp;
	int		i;
	int		err;

	i = 1;
	err = EXIT_FAILURE;
	while (line->cmd->arg[i])
	{
		if (line->cmd->arg[i][0] == '.' || line->cmd->arg[i][0] == '/')
		{
			if (!access(line->cmd->arg[i], X_OK))
			{
				printf("%s is %s\n", line->cmd->arg[i], line->cmd->arg[i]);
				err = (EXIT_SUCCESS);
			}
			else
			{
				printf("type : %s not found\n", line->cmd->arg[i]);
				err = (EXIT_FAILURE);
			}
		}
		if (ft_is_bi(line->cmd->arg[i]))
		{
			printf("%s is minishell built-in\n", line->cmd->arg[i]);
			err = (EXIT_SUCCESS);
		}
		else
		{
			tmp = ft_strdup(line->cmd->arg[i]);
			if (ft_get_path(get_value(line->lst_env, "PATH"), &line->cmd->arg[i]))
				printf("type : %s not found\n", tmp);
			else
				printf("%s is %s\n", tmp, line->cmd->arg[i]);
			free(tmp);
		}
		i++;
	}
	return (err);
}
