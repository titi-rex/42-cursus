/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:18:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/09 14:32:33 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_echo(t_line *line)
{
	char	new_line;
	int		i;

	i = 1;
	new_line = '\n';
	if (line->cmd && line->cmd->arg)
	{
		if (line->cmd->arg[1] && !ft_strncmp(line->cmd->arg[1], "-n", 3))
		{
			new_line = '\0';
			i++;
		}
		while (line->cmd->arg[i])
		{
			printf("%s", line->cmd->arg[i]);
			i++;
		}
	}
	printf("%c", new_line);
	return (EXIT_SUCCESS);
}
