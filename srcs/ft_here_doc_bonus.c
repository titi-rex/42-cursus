/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:35:25 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/26 19:40:56 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_here_doc(char *end, t_pipex *cmd_line)
{
	int		n_read;
	int		len_end;
	char	buff[100];

	if (pipe(cmd_line->pipe[1]) == -1)
		return ((void) ft_error("Pipe creation failed in here_doc", NULL, \
			&cmd_line->err));
	cmd_line->fds[0] = cmd_line->pipe[1][0];
	n_read = 1;
	len_end = ft_strlen(end);
	while (n_read)
	{
		n_read = read(0, &buff, 100);
		if (n_read == -1)
			break ;
		buff[n_read] = 0;
		if (!ft_strncmp(buff, end, len_end) && buff[len_end] == '\n')
			break ;
		write(cmd_line->pipe[1][1], &buff, n_read);
	}
}

void	ft_get_fd_doc(t_pipex *cmd_l, char **arg, int argc)
{
	int		n;

	n = argc - 1;
	if (ft_strncmp(arg[1], "here_doc", 9))
	{
		if (access(arg[1], F_OK))
			ft_error("Can't open file (no such file) : ", arg[1], &cmd_l->err);
		else if (access(arg[1], R_OK))
			ft_error("Can't open file : (permission denied) : ", arg[1], \
				&cmd_l->err);
		cmd_l->fds[0] = open(arg[1], O_RDONLY | O_CLOEXEC);
		cmd_l->fds[1] = open(arg[n], 01 | O_TRUNC | O_CLOEXEC | O_CREAT, 420);
	}
	else
		cmd_l->fds[1] = open(arg[n], 01 | O_CLOEXEC | O_APPEND | O_CREAT, 420);
	if (cmd_l->fds[1] == -1)
		ft_error("Can't open file : (permission denied) : ", arg[n], \
			&cmd_l->err);
}

void	ft_parsing_doc(char **argv, int argc, int start, t_pipex *cmd_line)
{
	int	i;

	cmd_line->n_cmd = argc - (start + 1);
	cmd_line->cmds = ft_calloc(cmd_line->n_cmd + 1, sizeof(void *));
	cmd_line->pipe[0][0] = -1;
	cmd_line->pipe[0][1] = -1;
	cmd_line->pipe[1][0] = -1;
	cmd_line->pipe[1][1] = -1;
	cmd_line->fds[0] = -1;
	cmd_line->fds[1] = -1;
	if (!cmd_line->cmds)
	{
		ft_error("Malloc failed for cmds", NULL, &cmd_line->err);
		ft_clean_exit(cmd_line, cmd_line->err);
	}
	i = 0;
	ft_get_argv(argv, start, cmd_line);
	ft_get_fd_doc(cmd_line, argv, argc);
	if (!cmd_line->env)
		return ;
	while (cmd_line->env[i] && ft_strncmp(cmd_line->env[i], "PATH=", 5))
		i++;
	ft_get_path(cmd_line->env[i], cmd_line, &cmd_line->err);
}
