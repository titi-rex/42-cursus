/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:07:58 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/08 18:35:25 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_exe_cmd(t_cmd *cmd, int pipe_in[2], int pipe_out[2])
{
	int	pid;
	int	here_pipe[2];

	pid = fork();
	if (pid == -1)
		perror("Error ");
	else if (pid == 0)
	{
		if (ft_dup_redirect(cmd->io, here_pipe))
			perror("Error ");
		ft_dup_pipe(pipe_in, pipe_out);
		if (execve(cmd->cmd[0], cmd->cmd, NULL) == -1)
			perror("Error ");
		ft_clear_cmd(cmd);
		exit(EXIT_FAILURE);
	}
}

static void	ft_get_wait_status(int max_wait, int *exit_code)
{
	int	wstatus;
	int	i;

	i = -1;
	while (i++ < max_wait)
		waitpid(-1, &wstatus, 0);
	if (WIFEXITED(wstatus))
		*exit_code = WEXITSTATUS(wstatus);
}

/*	TODO: change built-in exe (merge is_bi and bi_select)
	need to have builtin done before
*/
void	ft_exe_master(t_line *line)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (line->cmd)
	{
		if (line->cmd->next)
		{
			if (pipe(line->pipe[i]) == -1)
				perror("Error ");
		}
		if (ft_is_bi(line->cmd->cmd[0]))
			ft_bi_selector(line, line->pipe[j], line->pipe[i]);
		else
			ft_exe_cmd(line->cmd, line->pipe[j], line->pipe[i]);
		ft_close_pipe(line->pipe[j]);
		i = i + 1 % 2;
		j = j + 1 % 2;
		line->cmd = line->cmd->next;
	}
	ft_get_wait_status(line->n_cmds, &line->exit_status);
}
