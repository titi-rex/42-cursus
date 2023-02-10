/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:10:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/10 16:50:57 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_getpath(char **paths, char *cmd_name)
{
	char	*buffer;
	int		j;

	j = 0;
	while (paths[j])
	{
		buffer = ft_strjoin(paths[j], cmd_name);
		if (!buffer)
			return (ft_error("Malloc fail : ", cmd_name, cmd_name, NULL));
		if (!access(buffer, F_OK))
		{
			free(cmd_name);
			return (buffer);
		}
		free(buffer);
		j++;
	}
	return (ft_error("Command not found : ", cmd_name, cmd_name, NULL));
}

void	*ft_getargv(char **argv, t_pipex *cmd_line)
{
	int	i;

	i = 0;
	while (i < cmd_line->n_cmd)
	{
		cmd_line->cmds[i] = ft_split(argv[i + 2], ' ');
		if (!cmd_line->cmds[i])
		{
			ft_free3d((void ***) cmd_line->cmds, 0, NULL);
			return (ft_error("Malloc failed ", NULL, NULL, NULL));
		}
		i++;
	}
}

void	*ft_parsing(char **argv, t_pipex *cmd_line, char *pathvar)
{
	char	**paths;
	int		i;

	while (*pathvar != '/')
		pathvar++;
	paths = ft_split_path(pathvar, ':');
	cmd_line->cmds = ft_calloc(cmd_line->n_cmd + 1, sizeof(void *));
	if (!paths || !cmd_line->cmds)
		return (NULL);
	//printsplit(paths);
	ft_getargv(argv, cmd_line);
	i = 0;
	while (i < cmd_line->n_cmd)
	{
		cmd_line->cmds[i][0] = ft_getpath(paths, cmd_line->cmds[i][0]);
		i++;
	}
	ft_freesplit(paths);
}

