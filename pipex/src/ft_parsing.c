/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:10:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/01 13:46:06 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_parsing(char **argv, int argc, int start, t_pipex *cmd_line)
{
	int	i;

	cmd_line->n_cmd = argc - (start + 1);
	cmd_line->in = argv[1];
	cmd_line->out = argv[argc - 1];
	cmd_line->pipe[0][0] = -1;
	cmd_line->pipe[0][1] = -1;
	cmd_line->pipe[1][0] = -1;
	cmd_line->pipe[1][1] = -1;
	cmd_line->cmds = ft_calloc(cmd_line->n_cmd + 1, sizeof(void *));
	if (!cmd_line->cmds)
	{
		ft_error("cmd_line->cmds ", &cmd_line->err);
		ft_clean_exit(cmd_line, cmd_line->err);
	}
	i = 0;
	ft_get_argv(argv, start, cmd_line);
	if (!cmd_line->env)
		return ;
	while (cmd_line->env[i] && ft_strncmp(cmd_line->env[i], "PATH=", 5))
		i++;
	ft_get_path(cmd_line->env[i], cmd_line, &cmd_line->err);
}
