/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:07:58 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/09 20:37:31 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_exe_bi(t_line *line, int pipe_in[2], int pipe_out[2], \
	int (*ft_bi)(t_line *))
{
	int	here_pipe[2];
	int	pid;

	if (line->n_cmds == 1)
	{
		if (ft_dup_redirect(line->cmd->io, here_pipe))
			return ;
		line->exit_status = ft_bi(line);
	}
	else
	{
		pid = fork();
		if (pid == -1)
			perror("Error ");
		else if (pid == 0)
		{
			if (ft_dup_redirect(line->cmd->io, here_pipe))
				ft_clear_line_exit(line, EXIT_FAILURE);
			if (dup2(pipe_in[0], 0) == -1 || dup2(pipe_out[1], 1) == -1)
				perror("Error ");
			line->exit_status = ft_bi(line);
			ft_clear_line_exit(line, EXIT_SUCCESS);
		}
	}
}

void	ft_exe_cmd(t_line *line, int pipe_in[2], int pipe_out[2])
{
	int	pid;
	int	here_pipe[2];

	pid = fork();
	if (pid == -1)
		perror("Error ");
	else if (pid == 0)
	{
		if (ft_dup_redirect(line->cmd->io, here_pipe))
			perror("Error ");
		ft_dup_pipe(pipe_in, pipe_out);
		if (execve(line->cmd->arg[0], line->cmd->arg, NULL) == -1)
			perror("Error ");
		ft_clear_line_exit(line, EXIT_FAILURE);
	}
}

void	ft_exe_selector(t_line *line, int pipe_in[2], int pipe_out[2])
{
	if (!line->cmd->arg[0])
		return ;
	else if (!ft_strncmp(line->cmd->arg[0], "cd", 3))
		ft_exe_bi(line, pipe_in, pipe_out, bi_cd);
	else if (line->cmd->arg && !ft_strncmp(line->cmd->arg[0], "echo", 5))
		ft_exe_bi(line, pipe_in, pipe_out, bi_echo);
	//else if (line->cmd->arg && !ft_strncmp(line->cmd->arg[0], "env", 4))
	//	ft_exe_bi(line, pipe_in, pipe_out, bi_env);
	else if (line->cmd->arg && !ft_strncmp(line->cmd->arg[0], "exit", 5))
		ft_exe_bi(line, pipe_in, pipe_out, bi_exit);
	//else if (line->cmd->arg && !ft_strncmp(line->cmd->arg[0], "export", 7))
	//	ft_exe_bi(line, pipe_in, pipe_out, bi_export);
	else if (line->cmd->arg && !ft_strncmp(line->cmd->arg[0], "pwd", 4))
		ft_exe_bi(line, pipe_in, pipe_out, bi_pwd);
	//else if (line->cmd->arg && !ft_strncmp(line->cmd->arg[0], "unset", 6))
	//	ft_exe_bi(line, pipe_in, pipe_out, bi_unset);
	else
		ft_exe_cmd(line, pipe_in, pipe_out);
}

void	ft_get_wait_status(int max_wait, int *exit_code)
{
	int	wstatus;
	int	i;

	i = -1;
	while (i++ < max_wait)
		waitpid(-1, &wstatus, 0);
	if (WIFEXITED(wstatus))
		*exit_code = WEXITSTATUS(wstatus);
}

/*	TODO: ft_reset_line after exe master	*/
void	ft_exe_master(t_line *line)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (line->n_cmds && line->cmd)
	{
		if (line->cmd->next)
		{
			if (pipe(line->pipe[i]) == -1)
				perror("Error1 ");
		}
		ft_exe_selector(line, line->pipe[j], line->pipe[i]);
		ft_close_pipe(line->pipe[j]);
		i = i + 1 % 2;
		j = j + 1 % 2;
		if (!line->cmd->next)
			break ;
		line->cmd = line->cmd->next;
	}
	ft_get_wait_status(line->n_cmds, &line->exit_status);
	ft_clear_line(line);
}
