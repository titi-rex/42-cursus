/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:20:18 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/23 11:03:52 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**ft_split_path(char const *s)
{
	char	**split;
	char	*tmp;
	int		i;

	split = ft_split(s, ':');
	i = 0;
	while (split[i])
	{
		tmp = ft_strjoin(split[i], "/");
		free(split[i]);
		split[i] = tmp;
		i++;
	}
	return (split);
}

char	*ft_get_pathcmd(char **paths, char *cmd_name)
{
	char	*buffer;
	int		j;

	j = 0;
	while (cmd_name && paths[j])
	{
		buffer = ft_strjoin(paths[j], cmd_name);
		if (!buffer)
		{
			ft_error("Malloc failed in ft_get_pathcmd for cmd : ", cmd_name);
			free(cmd_name);
			return (NULL);
		}
		if (!access(buffer, F_OK))
		{
			free(cmd_name);
			return (buffer);
		}
		free(buffer);
		j++;
	}
	ft_error("Command not found : ", cmd_name);
	free(cmd_name);
	return (NULL);
}

void	ft_get_path(char *pathvar, t_pipex *cmd_line)
{
	char	**paths;
	int		i;

	if (!pathvar)
		return ;
	while (*pathvar != '/')
		pathvar++;
	paths = ft_split_path(pathvar);
	if (!paths)
	{
		ft_error("Mailoc from ft_split_path failed", NULL);
		ft_freesplit(paths);
		ft_clean_exit(cmd_line, EXIT_FAILURE);
	}
	i = 0;
	while (i < cmd_line->n_cmd)
	{
		if (cmd_line->cmds[i][0] == NULL)
			ft_error("Command empty", NULL);
		else if (cmd_line->cmds[i][0] && access(cmd_line->cmds[i][0], X_OK) && \
			cmd_line->cmds[i][0][0] != '.' && cmd_line->cmds[i][0][0] != '/')
			cmd_line->cmds[i][0] = ft_get_pathcmd(paths, cmd_line->cmds[i][0]);
		i++;
	}
	ft_freesplit(paths);
}
