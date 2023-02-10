/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:35:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/10 21:52:21 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *errstr, char *cmd_name)
{
	ft_putstr_fd("Error\n", 2);
	if (!cmd_name)
		ft_putendl_fd(errstr, 2);
	else
	{
		ft_putstr_fd(errstr, 2);
		ft_putendl_fd(cmd_name, 2);
	}
}

int	ft_man(void)
{
	ft_printf("use me correctly u stupid nerd!\n");
	ft_printf("Like that : ./pipex input_file cmd1 cmd2 output_file\n");
	return (0);
}

int	ft_pathlen(char *pathvar)
{
	int	len;

	len = 0;
	while (pathvar[len] != ':')
		len++;
	return (len);
}

void	ft_clean_exit(t_pipex *cmd_line, int exit_code)
{
	if (cmd_line->cmds)
		ft_free3d((void ***) cmd_line->cmds, 0, NULL);
	if (cmd_line->cmdio)
		ft_free2d((void **) cmd_line->cmdio, cmd_line->n_cmd);
	close(cmd_line->fds[0]);
	close(cmd_line->fds[1]);
	close(cmd_line->pipefd[0][0]);
	close(cmd_line->pipefd[0][1]);
	close(cmd_line->pipefd[1][0]);
	close(cmd_line->pipefd[1][1]);
	exit(exit_code);
}