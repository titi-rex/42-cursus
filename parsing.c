/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:10:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/09 15:45:54 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_parsing(char **argv, t_pipex *cmd_line, char *pathvar)
{
	char	**paths;
	int		i;

	while (*pathvar != '/')
		pathvar++;
	paths = ft_split_path(pathvar, ':');
	cmd_line->cmds = ft_calloc(cmd_line->n_cmd, sizeof(void *));
	if (!paths || !cmd_line->cmds)
		return(NULL);
	i = 0;
	while (i < cmd_line->n_cmd)
	{
		cmd_line->cmds[i] = ft_split(argv[i + 2], ' ');
		i++;
	}
	ft_freesplit(paths);
}