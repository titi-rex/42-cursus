/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:18:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/09 20:20:13 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_echo(t_line *line)
{
	char	new_line;
	int		i;
	int		err;

	i = 1;
	err = EXIT_SUCCESS;
	new_line = '\n';
	if (line->cmd->arg[1] && !ft_strncmp(line->cmd->arg[1], "-n", 3))
	{
		new_line = '\0';
		i++;
	}
	while (line->cmd->arg[i])
	{
		if (printf("%s", line->cmd->arg[i]) < 0)
			err = EXIT_FAILURE;
		i++;
		if (line->cmd->arg[i] && printf(" ") < 0)
			err = EXIT_FAILURE;
	}
	if (printf("%c", new_line))
		err = EXIT_FAILURE;
	return (err);
}
