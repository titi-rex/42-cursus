/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:25:56 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/25 17:26:47 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



int		ft_pathlen(char *pathvar)
{
	int	len;

	len = 0;
	while (pathvar[len] != ':')
		len++;
	return (len);
}

char	**ft_cmd_search(char *cmd, char *pathvar)
{
	char	*path;
	char	*buff;
	char	**cmd_formated;
	int		varlen;
	int		pathlen;

	while(*pathvar != '/')
		pathvar++;
	buff = ft_strtrim(cmd, " \t");
	varlen = ft_strlen(pathvar);
	while(varlen > 0)
	{
		pathlen = ft_pathlen(pathvar);
		path = ft_substr(pathvar, 0, pathlen);
		cmd_formated = ft_cmd_format(buff, path);
		free(path);
		if (!access(cmd_formated[0], F_OK))
		{
			free(buff);
			return (cmd_formated);
		}
		ft_freesplit(cmd_formated);
		pathvar += pathlen + 1;
		varlen -= pathlen - 1;
	}
	free(buff);
	ft_putstr_fd("Command not found\n", 2);
	return (NULL);
}

char	**ft_cmd_format(char *cmd, char *path)
{
	char	*buffer;
	char	**cmd_formated;
	int		cmd_len;
	int		path_len;

	cmd_len = ft_strlen(cmd);
	path_len = ft_strlen(path);
	buffer = (char *)ft_calloc(cmd_len + path_len + 2, sizeof(char));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, path, path_len + 1);
	buffer[path_len] = '/';
	ft_strlcpy(buffer + path_len + 1, cmd, cmd_len + 1);
	cmd_formated = ft_split(buffer, ' ');
	free(buffer);
	return (cmd_formated);
}

void	ft_cmd_check(char **cmd)
{
	if (access(cmd[0], X_OK) == -1)
		ft_error("You're not authorized to use this command !\n", cmd);
}

void	ft_cmd_exec(int fdin, int fdout, char **cmd)
{
	pid_t	child_pid;
	
	child_pid = fork();
	if (child_pid != 0 && child_pid != -1)
	{
		//ft_printf("parent here waiting for chpid is %d\n", child_pid);
		waitpid(child_pid, NULL, 0);
	}
	if (child_pid == 0)
	{
		//ft_printf("chpid here is %d\n", getpid());
		//ft_printf("fdin is %d, fdout is %d, cmd is %s\n", fdin, fdout, cmd[0]);
		//close(fdclose);
		//if (fdin != 0)
			dup2(fdin, 0);
		//if (fdout != 1)
			dup2(fdout, 1);
		if (execve(cmd[0], cmd, NULL) == -1)
				ft_putstr_fd("Error execve\n", 2);
		close(fdout);
		close(fdin);
		exit(EXIT_SUCCESS);
	}
}


/*
	if (child_pid == 0)
	{
		ft_printf("pid is %d\n", getpid());
		ft_printf("fdin is %d, fdout is %d, fdclose is %d, cmd is %s\n", fdin, fdout, fdclose, cmd[0]);
		//close(fdclose);
		dup2(fdin, 0);
		dup2(fdout, 1);
		child_pid2 = fork();
		waitpid(child_pid2, NULL, 0);
		if (child_pid2 == 0)
		{
			if (execve(cmd[0], cmd, NULL) == -1)
				ft_putstr_fd("Error execve\n", 2);
		}
		//close(fdout);
		//close(fdin);
		sleep(1);
		//ft_printf("end child\n");
		exit(EXIT_SUCCESS);
	}


	if (fork() == 0)
	{
		close(fdclose);
		dup2(fdin, 0);
		dup2(fdout, 1);
		if (execve(cmd[0], cmd, NULL) == -1)
			ft_putstr_fd("Error execve\n", 2);
		close(fdout);
		close(fdin);
	}
*/

/*
dup2(fdin, 0);
		dup2(fdout, 1);
		if (execve(cmd[0], cmd, NULL) == -1)
			ft_putstr_fd("Error execve\n", 2);
		close(fdout);
		close(fdin);
*/