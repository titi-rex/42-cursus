/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:25:56 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/23 23:35:43 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_cmd_format(char *cmd)
{
	char	*buffer;
	char	**cmd_formated;

	buffer = ft_strjoin("/usr/bin/", cmd);
	if (!buffer)
		return (NULL);
	cmd_formated = ft_split(buffer, ' ');
	free(buffer);
	return (cmd_formated);
}

void	ft_cmd_check(char **cmd)
{
	if (access(cmd[0], F_OK) == -1)
		ft_error("Command not found\n", cmd);
	if (access(cmd[0], X_OK) == -1)
		ft_error("You're not authorized to use this command !\n", cmd);
}

void	ft_cmd_exec(int fdin, int fdout, int fdclose, char **cmd)
{
	if (fork() == 0)
	{
		close(fdclose);
		dup2(fdin, 0);
		dup2(fdout, 1);
		if (execve(cmd[0], cmd, NULL) == -1)
			perror("error exe\n");
		close(fdout);
		close(fdin);
	}
}
