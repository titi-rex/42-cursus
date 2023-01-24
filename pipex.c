/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:30:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/24 20:17:58 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	char	**cmd;
	int		pipefd[2];
	int		fd;

	if (argc == 5)
	{
		if (pipe(pipefd))
			ft_error("pipe error\n", NULL);
		/* cmd1 */
		cmd = ft_cmd_search(argv[2], env[6]);
		if (!cmd)
			ft_error("malloc fail\n", NULL);
		if (access(cmd[0], X_OK) == -1)
			ft_error("You're not authorized to use this command !\n", cmd);
		fd = open(argv[1], O_RDONLY);
		ft_cmd_exec(fd, pipefd[1], pipefd[0], cmd);
		ft_freesplit(cmd);
		close(fd);
		/* cmd2 */
		cmd = ft_cmd_search(argv[3], env[6]);
		if (!cmd)
			ft_error("malloc fail\n", NULL);
		if (access(cmd[0], X_OK) == -1)
			ft_error("You're not authorized to use this command !\n", cmd);
		fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
		ft_cmd_exec(pipefd[0], fd, pipefd[1], cmd);
		ft_freesplit(cmd);
		close(fd);
		/* close fd */
		close(pipefd[1]);
		close(pipefd[0]);
	}	
	return (0);
}



/*
O_RDWR


		if (0 == fork())
		{
			close(pipefd[0]);
			fdin = open(argv[1], O_RDONLY);
			dup2(fdin, 0);
			dup2(fdf1, 1);
			if (execve(cmd[0], cmd, NULL) == -1)
				perror("error exe\n");
			close(pipefd[1]);
			close(fdin);
		}


valgrind --track-fd=yes ./exe
*/