/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:10:16 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/29 21:01:52 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_pwd(t_line *line)
{
	char	*pwd;

	if (line->cmd->arg[1] && line->cmd->arg[1][0] == '-' && \
		line->cmd->arg[1][1] != '\0')
		return (perror("Error : no option available "), 2);
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		pwd = env_get_value(line->lst_env, "PWD");
		if (!pwd)
			return (perror("Error no pwd available "), EXIT_FAILURE);
		if (printf("%s\n", pwd) < 0)
			return (perror("Error printf "), EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	if (printf("%s\n", pwd) < 0)
	{
		perror("Error printf ");
		free(pwd);
		return (EXIT_FAILURE);
	}
	free(pwd);
	return (EXIT_SUCCESS);
}
