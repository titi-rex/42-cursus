/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:30:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/11 21:23:57 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_old.h"


/*
big struct for cmd and path (store path in split)
use pipes
parsing cmd : path cmd + arg + i/o
execmd
*/
int	main(int argc, char **argv, char **env)
{
	int		i;

	if (argc < 5)
		return (ft_man());
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!ft_strncmp(argv[1], "here_doc", 9))
		ft_append_mode(argc, argv, env[i]);
	else
		ft_normal_mode(argc, argv, env[i], 2);
	if (!access(PIPEX_TMP_FILE, F_OK))
	{
		if (unlink(PIPEX_TMP_FILE))
			ft_error("Error deletion tmp file (pipex)", NULL, NULL);
	}
	return (0);
}

void	ft_normal_mode(int argc, char **argv, char *pathvar, int start)
{
	int	i;

	i = start;
	while (i < argc - 1)
	{
		if (i == start)
			ft_cmd_master(argv[i], argv[1], PIPEX_TMP_FILE, pathvar);
		else if (i == argc - 2)
			ft_cmd_master(argv[i], PIPEX_TMP_FILE, argv[argc - 1], pathvar);
		else
			ft_cmd_master(argv[i], PIPEX_TMP_FILE, PIPEX_TMP_FILE, pathvar);
		i++;
	}
}

void	ft_append_mode(int argc, char **argv, char *pathvar)
{
	if (ft_here_doc(argv[2]) == 1)
		ft_error("Open here_doc failed", NULL, NULL);
	ft_normal_mode(argc, argv, pathvar, 3);
	if (!access(HERE_DOC, F_OK))
	{
		if (unlink(HERE_DOC))
			ft_error("Error deletion tmp file (here_doc)", NULL, NULL);
	}
}

void	ft_cmd_master(char *cmd_raw, char *file1, char *file2, char *pathvar)
{
	char	**cmd;
	char	*buff;

	buff = ft_strtrim(cmd_raw, " \t");
	if (!buff)
		return ((void) ft_error("Malloc fail : ", cmd_raw, NULL));
	cmd = ft_cmd_search(buff, pathvar);
	free(buff);
	if (!cmd)
		return ;
	if (access(cmd[0], X_OK) == -1)
	{
		ft_freesplit(cmd);
		ft_error("You're not authorized to use this command !\n", cmd[0], NULL);
		return ;
	}
	ft_cmd_exec(file1, file2, cmd);
	ft_freesplit(cmd);
}
