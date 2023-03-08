/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:17:01 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/08 16:36:04 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_is_bi(char *name)
{
	if (!ft_strncmp(name, "cd", 3))
		return (1);
	if (!ft_strncmp(name, "echo", 5))
		return (1);
	if (!ft_strncmp(name, "env", 4))
		return (1);
	if (!ft_strncmp(name, "exit", 5))
		return (1);
	if (!ft_strncmp(name, "export", 7))
		return (1);
	if (!ft_strncmp(name, "pwd", 4))
		return (1);
	return (0);
}

void	ft_bi_selector(t_line *line, int pipe_in[2], int pipe_out[2])
{
	ft_dup_redirect(line->cmd->io);
	//ft_dup_pipe(pipe_in, pipe_out);
	if (!ft_strncmp(line->cmd->cmd[0], "cd", 3))
		line->exit_status = (line->cmd->cmd);
	if (!ft_strncmp(line->cmd->cmd[0], "echo", 5))
		line->exit_status = bi_echo(line->cmd->cmd);
	//if (!ft_strncmp(line->cmd->cmd[0], "env", 4))
	//	env();
	if (!ft_strncmp(line->cmd->cmd[0], "exit", 5))
		bi_exit(line, line->cmd->cmd[1]);
	//if (!ft_strncmp(line->cmd->cmd[0], "export", 7))
	//	return (1);
	if (!ft_strncmp(line->cmd->cmd[0], "pwd", 4))
		line->exit_status = bi_pwd();
}

