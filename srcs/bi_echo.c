/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:18:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/09 13:26:58 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_echo(t_line *line)
{
	char	new_line;
	int		i;

	i = 1;
	new_line = '\n';
	if (line->cmd->cmd[1] && !ft_strncmp(line->cmd->cmd[1], "-n", 3))
	{
		new_line = '\0';
		i++;
	}
	while (line->cmd->cmd[i])
	{
		printf("%s", line->cmd->cmd[i]);
		i++;
	}
	printf("%c", new_line);
	return (EXIT_SUCCESS);
}
