/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_dup_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:17:17 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/23 16:31:57 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_dup_it(t_redirect *io, int fd_std, int flag)
{
	int	fd;
	int	err;

	fd = open(io->arg, flag, 0644);
	if (fd == -1)
		return (1);
	err = 0;
	if (dup2(fd, fd_std) == -1)
		err = 1;
	close(fd);
	return (err);
}

int	ft_dup_here_doc(t_redirect *io, int here_pipe[2], t_line *line)
{
	int		pid;
	int		i;


	if (pipe(here_pipe) == -1)
		return (ft_perror_return_int(NULL));
	pid = fork();
	if (pid == -1)
		perror("Error ");
	else if (pid == 0)
	{
		i = -1;
		while (io->arg[++i])
			write(here_pipe[1], &io->arg[i], 1);
		ft_close_pipe(here_pipe);
		ft_clean_exit(line, EXIT_SUCCESS);
	}
	else
	{
		if (dup2(here_pipe[0], 0) == -1)
			perror("Error dup here_doc ");
		ft_close_pipe(here_pipe);
		ft_close_pipe(line->fd_std);
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
