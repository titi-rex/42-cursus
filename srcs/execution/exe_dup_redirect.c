/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_dup_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:17:17 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/21 19:50:01 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_dup_it(t_redirect *io, int fd_std, int flag)
{
	int	fd;

	fd = open(io->arg, flag, 0644);
	if (fd == -1)
	{
		perror("Error dup io ");
		return (1);
	}
	if (dup2(fd, fd_std) == -1)
		perror("Error dup io ");
	close(fd);
	return (0);
}

int	ft_dup_here_doc(t_redirect *io, int here_pipe[2], t_line *line)
{
	int	pid;

	if (pipe(here_pipe) == -1)
		return (ft_perror_return_int(NULL));
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
		ft_close_pipe(here_pipe);
		ft_clean_exit(line, EXIT_SUCCESS);
	}
	else
	{
		if (dup2(here_pipe[1], 0) == -1)
			perror("Error dup here_doc ");
		ft_close_pipe(here_pipe);
	}
	return (0);
}

int	ft_dup_redirect(t_list *io, int here_pipe[2], t_line *line)
{
	while (io)
	{
		if (*ft_redirect_acces_type(io->content) == 0 && \
			ft_dup_it(io->content, 0, O_RDONLY))
			return (1);
		else if (*ft_redirect_acces_type(io->content) == 1 && \
			ft_dup_it(io->content, 1, O_WRONLY | O_TRUNC | O_CREAT))
			return (1);
		else if (*ft_redirect_acces_type(io->content) == 2 && \
			ft_dup_here_doc(io->content, here_pipe, line))
			return (1);
		else if (*ft_redirect_acces_type(io->content) == 3 && \
			ft_dup_it(io->content, 1, O_WRONLY | O_APPEND | O_CREAT))
			return (1);
		io = io->next;
	}
	return (0);
}

/*
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
*/

/*
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

static int	ft_dup_(t_redirect *io)
{
	int	fd;

	fd = open(io->arg, O_RDONLY, 0644);
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
*/