/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:35:47 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/17 21:18:23 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_get_pathcmd(char **paths, char *cmd_name)
{
	char	*buffer;
	int		j;

	j = 0;
	while (cmd_name && paths[j])
	{
		buffer = ft_strjoin3(paths[j], "/", cmd_name);
		if (!buffer)
		{
			perror(cmd_name);
			free(cmd_name);
			return (NULL);
		}
		if (!access(buffer, F_OK))
		{
			free(cmd_name);
			return (buffer);
		}
		j++;
	}
	free(buffer);
	buffer = ft_strdup(cmd_name);
	free(cmd_name);
	return (buffer);
}

void	ft_get_path(char *pathvar, t_cmd *cmd)
{
	char	**paths;

	if (!pathvar)
		return ;
	paths = ft_split(pathvar, ':');
	if (!paths)
	{
		perror("Error ");
		return ;
	}
	if (cmd->arg[0] == NULL)
		return ;
	else if (access(cmd->arg[0], X_OK) && \
		cmd->arg[0][0] != '.' && cmd->arg[0][0] != '/')
		cmd->arg[0] = ft_get_pathcmd(paths, cmd->arg[0]);
	ft_free2d((void **)paths, 0);
}
