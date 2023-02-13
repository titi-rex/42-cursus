/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:10:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/13 17:42:31 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_parsing(char **argv, int argc, int start, t_pipex *cmd_line)
{
	int	i;

	cmd_line->n_cmd = argc - (start + 1);
	cmd_line->cmds = ft_calloc(cmd_line->n_cmd + 1, sizeof(void *));
	if (!cmd_line->cmds)
	{
		ft_error("Malloc failed for cmds", NULL);
		ft_clean_exit(cmd_line, EXIT_FAILURE);
	}
	if (pipe(cmd_line->pipe[1]) == -1)
	{
		ft_error("Pipe creation failed ", NULL);
		ft_clean_exit(cmd_line, EXIT_FAILURE);
	}
	i = 0;
	while (cmd_line->env[i] && ft_strncmp(cmd_line->env[i], "PATH=", 5))
		i++;
	ft_get_argv(argv, start, cmd_line);
	ft_get_path(cmd_line->env[i], cmd_line);
	ft_get_fd(cmd_line, argv, argc);
}
