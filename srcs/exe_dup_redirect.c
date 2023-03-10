/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_dup_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:17:17 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/10 13:12:29 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_dup_in(t_redirect *io)
{
	int	fd;

	fd = open(io->arg, O_RDONLY);
	if (fd == -1)
	{
		perror("Error dup io < ");
		return (1);
	}
	if (dup2(fd, io->fd) == -1)
		perror("Error dup io < ");
	close(fd);
	return (0);
}

static int	ft_dup_out(t_redirect *io)
{
	int	fd;

	fd = open(io->arg, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("Error dup io > ");
		return (1);
	}
	if (dup2(fd, io->fd) == -1)
		perror("Error dup io > ");
	close(fd);
	return (0);
}

static int	ft_dup_out_append(t_redirect *io)
{
	int	fd;

	fd = open(io->arg, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("Error dup io >> ");
		return (1);
	}
	if (dup2(fd, io->fd) == -1)
		perror("Error dup io >> ");
	close(fd);
	return (0);
}

static int	ft_dup_here_doc(t_redirect *io, int here_pipe[2])
{
	if (pipe(here_pipe) == -1)
	{
		perror("Error ");
		return (1);
	}
	if (write(here_pipe[0], io->arg, ft_strlen(io->arg)) == -1)
		perror("Error dup here_doc ");
	if (dup2(here_pipe[1], 0) == -1)
		perror("Error dup here_doc ");
	ft_close_pipe(here_pipe);
	return (0);
}

int	ft_dup_here_doc_v2(t_redirect *io, int here_pipe[2], t_line *line)
{
	int	pid;

	if (pipe(here_pipe) == -1)
	{
		perror("Error ");
		return (1);
	}
	pid = fork();
	if (pid == -1)
		perror("Error ");
	else if (pid == 0)
	{
		while (io->arg)
		{
			write(here_pipe[0], io->arg, 1);
			io->arg++;
		}
		ft_clear_line_exit(line, EXIT_SUCCESS);
	}
	else
	{
		if (dup2(here_pipe[1], 0) == -1)
			perror("Error dup here_doc ");
		ft_close_pipe(here_pipe);
	}
	return (0);
}

/*	TODO: check if format like io->type 0 works	*/
int	ft_dup_redirect(t_redirect *io, int here_pipe[2])
{
	while (io)
	{
		if (io->type == 0 && ft_dup_in(io))
			return (1);
		else if (io->type == 1)
		{
			if (ft_dup_out(io))
				return (1);
		}
		else if (io->type == 2)
		{
			if (ft_dup_here_doc(io, here_pipe))
				return (1);
		}
		else if (io->type == 3)
		{
			if (ft_dup_out_append(io))
				return (1);
		}
		io = io->next;
	}
	return (0);
}
