/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:30:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/23 21:32:02 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	readnprint(int fd)
{
	char	c;
	int		i;

	i = 0;
	while (i < 51)
	{
		read(fd, &c, 1);
		write(1, &c, 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*buff;
	int		pipefd[2];
	int		fdout;


	if (argc == 2)
	{
		buff = ft_strjoin("/usr/bin/", argv[1]);
		if (access(buff, F_OK | X_OK) == -1)
			ft_error("acces denied 1\n");
		if (0 == fork())
		{
			fdout = open("filout", O_WRONLY);
			dup2(fdout, 1);
			if (execve(buff, ft_split(argv[1], ' '), NULL) == -1)
				perror("error exe\n");
			close(fdout);
		}
		free(buff);
	}
	if (argc == 3)
	{
		if (pipe(pipefd))
			ft_error("pipe error\n");
		buff = ft_strjoin("/usr/bin/", argv[1]);
		if (access(buff, F_OK | X_OK) == -1)
			ft_error("acces denied 1\n");
		if (0 == fork())
		{
			close(pipefd[0]);
			dup2(pipefd[1], 1);
			if (execve(buff, ft_split(argv[1], ' '), NULL) == -1)
				perror("error exe\n");
			close(pipefd[1]);
		}
		free(buff);
		buff = ft_strjoin("/usr/bin/", argv[2]);
		if (access(buff, F_OK | X_OK) == -1)
			ft_error("acces denied 1\n");
		if (0 == fork())
		{
			close(pipefd[1]);
			fdout = open("filout", O_WRONLY);
			dup2(pipefd[0], 0);
			dup2(fdout, 1);
			if (execve(buff, ft_split(argv[2], ' '), NULL) == -1)
				perror("error exe\n");
			close(pipefd[0]);
			close(fdout);
		}
		close(pipefd[1]);
		close(pipefd[0]);
	}	
	return (0);
}



/*
O_RDWR
*/