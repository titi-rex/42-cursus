/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:30:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/25 17:34:06 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* need to make a better error management */
int	main(int argc, char **argv, char **env)
{
	char	**cmd;
	char	*tmpfile_path;
	int		fd;
	int		fdtmp;

	
	tmpfile_path = "pipex_tmp";
	if (argc == 5)
	{
		/* cmd first */
		cmd = ft_cmd_search(argv[2], env[6]);
		if (!cmd)
			ft_error("malloc fail\n", NULL);
		if (access(cmd[0], X_OK) == -1)
			ft_error("You're not authorized to use this command !\n", cmd);
		fd = open(argv[1], O_RDONLY);
		fdtmp = open(tmpfile_path, O_RDWR | O_CREAT | O_TRUNC, 0644);
		ft_cmd_exec(fd, fdtmp, cmd);
		ft_freesplit(cmd);
		close(fd);
		close(fdtmp);

		ft_printf("MIDDLE\n");
		/* cmd end */
		cmd = ft_cmd_search(argv[3], env[6]);
		if (!cmd)
			ft_error("malloc fail\n", NULL);
		if (access(cmd[0], X_OK) == -1)
			ft_error("You're not authorized to use this command !\n", cmd);
		fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		fdtmp = open(tmpfile_path, O_RDWR);
		ft_cmd_exec(fdtmp, fdtmp, cmd);
		ft_freesplit(cmd);
		close(fd);
		//if (unlink(tmpfile_path))
			//ft_putstr_fd("Error rm tmp file \n", 2);
		close(fdtmp);
		ft_printf("END\n");

	}	
	return (0);
}

/*
		 

*/

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