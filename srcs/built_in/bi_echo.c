/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:18:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/25 20:15:45 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	bi_echo_is_flag(char *arg)
{
	int	i;

	if (arg[0] != '-')
		return (1);
	i = 1;
	while (arg[i] && arg[i] == 'n')
		i++;
	if (arg[i])
		return (1);
	return (0);
}

int	bi_echo(t_line *line)
{
	char	new_line;
	int		i;
	int		err;

	err = EXIT_SUCCESS;
	new_line = '\n';
	i = 0;
	while (line->cmd->arg[++i] && !bi_echo_is_flag(line->cmd->arg[i]))
		new_line = '\0';
	while (line->cmd->arg[i])
	{
		if (printf("%s", line->cmd->arg[i]) < 0)
			err = EXIT_FAILURE;
		i++;
		if (line->cmd->arg[i] && printf(" ") < 0)
			err = EXIT_FAILURE;
	}
	if (printf("%c", new_line) < 0)
		err = EXIT_FAILURE;
	return (err);
}
