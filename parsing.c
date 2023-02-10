/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:10:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/10 22:19:15 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	ft_get_argv(char **argv, t_pipex *cmd_line)
{
	int	i;

	i = 0;
	while (i < cmd_line->n_cmd)
	{
		cmd_line->cmds[i] = ft_split(argv[i + 2], ' ');
		if (!cmd_line->cmds[i])
		{
			ft_error("Malloc failed in ft_get_argv for cmd : ", argv[i + 2]);
			ft_clean_exit(cmd_line, EXIT_FAILURE);
		}
		i++;
	}
}

char	*ft_get_pathcmd(char **paths, char *cmd_name)
{
	char	*buffer;
	int		j;

	j = 0;
	while (paths[j])
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

	while (*pathvar != '/')
		pathvar++;
	paths = ft_split_path(pathvar, ':');
	if (!paths)
	{
		ft_error("Mailoc failed in ft_get_path", NULL);
		ft_freesplit(paths);
		ft_clean_exit(cmd_line, EXIT_FAILURE);
	}
	i = 0;
	while (i < cmd_line->n_cmd)
	{
		cmd_line->cmds[i][0] = ft_get_pathcmd(paths, cmd_line->cmds[i][0]);
		i++;
	}
	ft_freesplit(paths);
}

void	ft_assign_io(int cmdio[2], int input, int output)
{
	cmdio[0] = input;
	cmdio[1] = output;
}

void	ft_get_cmdio(t_pipex *cmd_line, int pipefd[2][2])
{
	int		i;
	int		j;
	int		k;
	
	i = 0;
	k = -1;
	j = 1;
	while (i < cmd_line->n_cmd)
	{
		cmd_line->cmdio[i] = ft_calloc(2, sizeof(int));
		if (!cmd_line->cmdio[i])
		{
			ft_error("Malloc failed in ft_get_cmdio", NULL);
			continue ;
		}
		if (i == 0)
			ft_assign_io(cmd_line->cmdio[i], cmd_line->fds[0], pipefd[j + k][1]);
		else if (i == cmd_line->n_cmd - 1)
			ft_assign_io(cmd_line->cmdio[i], pipefd[j][0], cmd_line->fds[1]);
		else
			ft_assign_io(cmd_line->cmdio[i], pipefd[j][0], pipefd[j + k][1]);
		i++;
		j += k;
		k *= -1;
	}
}


void	ft_parsing(char **argv, char *pathvar, t_pipex *cmd_line)
{
	int		i;

	cmd_line->cmds = ft_calloc(cmd_line->n_cmd + 1, sizeof(void *));
	cmd_line->cmdio = ft_calloc(cmd_line->n_cmd, sizeof(void *));
	if (!cmd_line->cmds || !cmd_line->cmdio)
	{
		ft_error("Malloc failed for cmds or cmdio", NULL);
		ft_clean_exit(cmd_line, EXIT_FAILURE);
	}
	ft_get_argv(argv, cmd_line);
	ft_get_path(pathvar, cmd_line);
	ft_get_cmdio(cmd_line, cmd_line->pipefd);
}
