/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_exe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:30:36 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/12 20:14:20 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_cmd_exe(t_pipex *cmd_l, int i)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_error("Fork failed ", NULL);
	else if (pid == 0)
	{
		if (cmd_l->cmdio[i][0] != -1 && cmd_l->cmdio[i][1] != -1)
		{
			dup2(cmd_l->cmdio[i][0], 0);
			dup2(cmd_l->cmdio[i][1], 1);
			ft_close(cmd_l);
			if (!cmd_l->cmds[i][0])
				ft_clean_exit(cmd_l, EXIT_FAILURE);
			if (execve(cmd_l->cmds[i][0], cmd_l->cmds[i], cmd_l->env) == -1)
				ft_error("Execve failed ", cmd_l->cmds[i][0]);
		}
		ft_clean_exit(cmd_l, EXIT_FAILURE);
	}
}

void	ft_cmd_master(t_pipex *cmd_line)
{
	int	i;

	i = 0;
	while (i < cmd_line->n_cmd)
	{
		ft_cmd_exe(cmd_line, i);
		i++;
	}
}
