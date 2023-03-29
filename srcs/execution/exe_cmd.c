/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:07:58 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/29 22:38:53 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern sig_atomic_t	g_status;

void	exe_bi(t_line *line, int pipe_in[2], int pipe_out[2], \
	int (*ft_bi)(t_line *))
{
	int	here_pipe[2];
	int	pid;

	exe_init_here_pipe(here_pipe);
	if (line->n_cmds == 1)
	{
		if (dup_selector(line->cmd->io, here_pipe, line))
			return ;
		line->exit_status = ft_bi(line);
		exe_restore_std(line->cmd->io, line->fd_std);
		return ;
	}
	pid = fork();
	if (pid == -1)
		perror("Error ");
	else if (pid == 0)
	{
		sig_init(sig_handler_child, sig_handler_child);
		dup_pipe(pipe_in, pipe_out);
		if (dup_selector(line->cmd->io, here_pipe, line))
			ft_clean_exit(line, EXIT_FAILURE);
		line->exit_status = ft_bi(line);
		ft_clean_exit(line, EXIT_SUCCESS);
	}
}

void	exe_cmd(t_line *line, int pipe_in[2], int pipe_out[2])
{
	int	pid;
	int	here_pipe[2];

	exe_init_here_pipe(here_pipe);
	pid = fork();
	if (pid == -1)
		perror("Error ");
	else if (pid == 0)
	{
		sig_init(sig_handler_child, sig_handler_child);
		dup_pipe(pipe_in, pipe_out);
		ft_close_pipe(line->fd_std);
		if (dup_selector(line->cmd->io, here_pipe, line))
			ft_clean_exit(line, EXIT_FAILURE);
		if (!line->cmd->arg[0] && line->cmd->io)
			ft_clean_exit(line, EXIT_SUCCESS);
		if (ft_path_get(env_get_value(line->lst_env, "PATH"), \
			&line->cmd->arg[0]))
			exe_error_404(line, line->cmd->arg[0]);
		if (access(line->cmd->arg[0], X_OK))
			exe_error_403(line, line->cmd->arg[0]);
		execve(line->cmd->arg[0], line->cmd->arg, line->env);
		perror("Error ");
		ft_clean_exit(line, EXIT_FAILURE);
	}
}

void	exe_selector(t_line *line, char **arg, int pipe_in[2], int pipe_out[2])
{
	if (arg[0] && !ft_strncmp(arg[0], "cd", 3))
		exe_bi(line, pipe_in, pipe_out, bi_cd);
	else if (arg[0] && arg && !ft_strncmp(arg[0], "echo", 5))
		exe_bi(line, pipe_in, pipe_out, bi_echo);
	else if (arg[0] && arg && !ft_strncmp(arg[0], "clear", 6))
		exe_bi(line, pipe_in, pipe_out, bi_clear);
	else if (arg[0] && arg && !ft_strncmp(arg[0], "env", 4))
		exe_bi(line, pipe_in, pipe_out, bi_env);
	else if (arg[0] && arg && !ft_strncmp(arg[0], "exit", 5))
		exe_bi(line, pipe_in, pipe_out, bi_exit);
	else if (arg[0] && arg && !ft_strncmp(arg[0], "export", 7))
		exe_bi(line, pipe_in, pipe_out, bi_export);
	else if (arg[0] && arg && !ft_strncmp(arg[0], "loulou", 7))
		exe_bi(line, pipe_in, pipe_out, bi_loulou);
	else if (arg[0] && arg && !ft_strncmp(arg[0], "pwd", 4))
		exe_bi(line, pipe_in, pipe_out, bi_pwd);
	else if (arg[0] && arg && !ft_strncmp(arg[0], "type", 5))
		exe_bi(line, pipe_in, pipe_out, bi_type);
	else if (arg[0] && arg && !ft_strncmp(arg[0], "titi", 5))
		exe_bi(line, pipe_in, pipe_out, bi_titi);
	else if (arg[0] && arg && !ft_strncmp(arg[0], "unset", 6))
		exe_bi(line, pipe_in, pipe_out, bi_unset);
	else
		exe_cmd(line, pipe_in, pipe_out);
}

static void	exe_get_wait_status(int max_wait, int *exit_code)
{
	int	wstatus;
	int	i;

	i = -1;
	wstatus = 0;
	while (++i < max_wait)
	{
		waitpid(-1, &wstatus, 0);
		if (WIFEXITED(wstatus))
			*exit_code = WEXITSTATUS(wstatus);
		if (WIFSIGNALED(wstatus))
		{
			*exit_code = WTERMSIG(wstatus) + 128;
			if (*exit_code == 131)
				ft_putstr_fd("Quit\n", 2);
		}
	}
}

void	exe_master(t_line *line)
{
	int	i;

	i = 0;
	if (!line->n_cmds)
		return ;
	g_status |= EXECUTION;
	while (i < line->n_cmds)
	{
		if (line->cmd->next)
		{
			if (pipe(line->pipe[i % 2]) == -1)
				perror("Error open pipe ");
		}
		exe_selector(line, line->cmd->arg, line->pipe[(i + 1) % 2], \
			line->pipe[i % 2]);
		ft_close_pipe(line->pipe[(i + 1) % 2]);
		i++;
		if (line->cmd->next)
			line->cmd = line->cmd->next;
	}
	if (line->n_cmds != 1 || !ft_is_bi(line->cmd->arg[0]))
		exe_get_wait_status(line->n_cmds, &line->exit_status);
	g_status ^= EXECUTION;
}
