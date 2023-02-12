/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:21:31 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/12 20:14:20 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_assign_io(int cmdio[2], int input, int output)
{
	cmdio[0] = input;
	cmdio[1] = output;
}

void	ft_get_cmdio(t_pipex *cmd_l, int pipefd[2][2])
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = -1;
	j = 1;
	while (i < cmd_l->n_cmd)
	{
		cmd_l->cmdio[i] = ft_calloc(2, sizeof(int));
		if (!cmd_l->cmdio[i])
		{
			ft_error("Malloc failed in ft_get_cmdio", NULL);
			ft_clean_exit(cmd_l, EXIT_FAILURE);
		}
		if (i == 0)
			ft_assign_io(cmd_l->cmdio[i], cmd_l->fds[0], pipefd[j + k][1]);
		else if (i == cmd_l->n_cmd - 1)
			ft_assign_io(cmd_l->cmdio[i], pipefd[j][0], cmd_l->fds[1]);
		else
			ft_assign_io(cmd_l->cmdio[i], pipefd[j][0], pipefd[j + k][1]);
		i++;
		j += k;
		k *= -1;
	}
}

void	ft_get_fd(t_pipex *cmd_l, char **arg, int argc)
{
	int	n;

	n = argc - 1;
	cmd_l->fds[0] = -1;
	cmd_l->fds[1] = -1;
	if (!access(arg[1], F_OK | R_OK))
		cmd_l->fds[0] = open(arg[1], O_RDONLY | O_CLOEXEC);
	else if (!ft_strncmp(arg[1], "here_doc", 9))
		cmd_l->fds[0] = cmd_l->pipefd[1][0];
	else
		ft_error("Can't open file : ", arg[1]);
	cmd_l->fds[1] = open(arg[n], O_WRONLY | O_TRUNC | O_CLOEXEC | O_CREAT, 420);
	if (cmd_l->fds[1] == -1)
		ft_error("Can't open file : ", arg[n]);
}
