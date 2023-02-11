/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:35:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/11 21:20:18 by tlegrand         ###   ########.fr       */
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

void	printsplit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		ft_printf("%s ", split[i]);
		i++;
	}
	ft_printf("\n");
}

void	printpipex(t_pipex *pipex)
{
	int	i;

	ft_printf("n_cmd is %d\n", pipex->n_cmd);
	ft_printf("fds[0] is %d\n", pipex->fds[0]);
	ft_printf("fds[1] is %d\n\n", pipex->fds[1]);
	ft_printf("pipfd[0][0] is %d\n", pipex->pipefd[0][0]);
	ft_printf("pipfd[0][1] is %d\n", pipex->pipefd[0][1]);
	ft_printf("pipfd[1][0] is %d\n", pipex->pipefd[1][0]);
	ft_printf("pipfd[1][1] is %d\n", pipex->pipefd[1][1]);
	ft_printf("\n###### cmd ######\n"),
	i = 0;
	while (pipex->cmds[i])
	{
		printsplit(pipex->cmds[i]);
		i++;
	}
	ft_printf("\n###### I/O ######\n");
	i = 0;
	while (i < pipex->n_cmd)
	{
		ft_printf("cmdio[%d][0] is %d\n", i, pipex->cmdio[i][0]);
		ft_printf("cmdio[%d][1] is %d\n", i, pipex->cmdio[i][1]);
		i++;
	}
	ft_printf("end\n\n");
}
