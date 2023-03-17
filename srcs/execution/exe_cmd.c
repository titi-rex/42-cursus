/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:07:58 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/17 22:50:25 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern sig_atomic_t	g_status;

void	ft_exe_bi(t_line *line, int pipe_in[2], int pipe_out[2], \
	int (*ft_bi)(t_line *))
{
	int	here_pipe[2];
	int	pid;

	if (line->n_cmds == 1)
	{
		if (ft_dup_redirect(line->cmd->io, here_pipe, line))
			return ;
		line->exit_status = ft_bi(line);
		dup2(line->fd_std[0], STDIN_FILENO);
		dup2(line->fd_std[1], STDOUT_FILENO);
	}
	else
	{
		pid = fork();
		if (pid == -1)
			perror("Error ");
		else if (pid == 0)
		{
			ft_sig_init(ft_sig_handler_child);
			ft_dup_pipe(pipe_in, pipe_out);
			if (ft_dup_redirect(line->cmd->io, here_pipe, line))
				ft_clean_exit(line, EXIT_FAILURE);
			line->exit_status = ft_bi(line);
			ft_clean_exit(line, EXIT_SUCCESS);
		}
	}
}

void	ft_exe_cmd(t_line *line, int pipe_in[2], int pipe_out[2])
{
	int	pid;
	int	here_pipe[2];

	if (!access(line->cmd->arg[0], X_OK) && !ft_strncmp(line->cmd->arg[0] \
		+ ft_strlen2(line->cmd->arg[0]) - 9, "minishell", 11))
		g_status |= MINISHELL;
	pid = fork();
	if (pid == -1)
		perror("Error ");
	else if (pid == 0)
	{
		ft_sig_init(ft_sig_handler_child);
		ft_dup_pipe(pipe_in, pipe_out);
		if (ft_dup_redirect(line->cmd->io, here_pipe, line))
			perror("Error ");
		if (!line->cmd->arg && line->cmd->io)
			ft_clean_exit(line, EXIT_SUCCESS);
		execve(line->cmd->arg[0], line->cmd->arg, line->env);
		perror("Error ");
		ft_clean_exit(line, EXIT_FAILURE);
	}
}

void	ft_exe_selector(t_line *line, int pipe_in[2], int pipe_out[2])
{
	if (!line->cmd->arg)
		ft_exe_cmd(line, pipe_in, pipe_out);
	if (!ft_strncmp(line->cmd->arg[0], "cd", 3))
		ft_exe_bi(line, pipe_in, pipe_out, bi_cd);
	else if (line->cmd->arg && !ft_strncmp(line->cmd->arg[0], "echo", 5))
		ft_exe_bi(line, pipe_in, pipe_out, bi_echo);
	else if (line->cmd->arg && !ft_strncmp(line->cmd->arg[0], "env", 4))
		ft_exe_bi(line, pipe_in, pipe_out, bi_env);
	else if (line->cmd->arg && !ft_strncmp(line->cmd->arg[0], "exit", 5))
		ft_exe_bi(line, pipe_in, pipe_out, bi_exit);
	else if (line->cmd->arg && !ft_strncmp(line->cmd->arg[0], "export", 7))
		ft_exe_bi(line, pipe_in, pipe_out, bi_export);
	else if (line->cmd->arg && !ft_strncmp(line->cmd->arg[0], "pwd", 4))
		ft_exe_bi(line, pipe_in, pipe_out, bi_pwd);
	else if (line->cmd->arg && !ft_strncmp(line->cmd->arg[0], "unset", 6))
		ft_exe_bi(line, pipe_in, pipe_out, bi_unset);
	else
		ft_exe_cmd(line, pipe_in, pipe_out);
}

void	ft_get_wait_status(int max_wait, int *exit_code)
{
	int	wstatus;
	int	i;
	int	pid;

	i = -1;
	wstatus = 0;
	while (++i < max_wait)
	{
		pid = waitpid(-1, &wstatus, 0);
		if (WIFEXITED(wstatus))
			*exit_code = WEXITSTATUS(wstatus);
		if (WIFSIGNALED(wstatus))
		{
			*exit_code = WTERMSIG(wstatus);
			if (WTERMSIG(wstatus) == 3)
				ft_putstr_fd("Quit\n", 2);
		}
		dprintf(2, "wait end for %d\n", pid);
	}
	dprintf(2, "all wait end, gstatsu : %d\n", g_status);
}

void	ft_exe_master(t_line *line)
{
	int	i;

	i = 0;
	if (!line->n_cmds)
		return ;
	g_status ^= READING;
	g_status |= EXECUTION;
	while (i < line->n_cmds)
	{
		//if (g_status == SIGINT)
		//	return ;
		if (line->cmd->next)
		{
			if (pipe(line->pipe[i % 2]) == -1)
				perror("Error open pipe ");
		}
		ft_exe_selector(line, line->pipe[(i + 1) % 2], line->pipe[i % 2]);
		ft_close_pipe(line->pipe[(i + 1) % 2]);
		i++;
		if (line->cmd->next)
			line->cmd = line->cmd->next;
	}
	if (line->n_cmds != 1 || !ft_is_bi(line->cmd->arg))
		ft_get_wait_status(line->n_cmds, &line->exit_status);
	if (line->n_cmds && ft_is_this_a_minishell(line))
		g_status ^= MINISHELL;
	g_status ^= EXECUTION;
}
