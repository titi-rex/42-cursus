/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:25:56 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/03 16:48:10 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pathlen(char *pathvar)
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
	int		pathlen;

	while (*pathvar != '/')
		pathvar++;
	buff = ft_strtrim(cmd, " \t");
	if (!buff)
		return (ft_error("Malloc fail : ", cmd, NULL));
	while (*pathvar == '/')
	{
		pathlen = ft_pathlen(pathvar);
		path = ft_substr(pathvar, 0, pathlen);
		if (!path)
			return (ft_error("Malloc fail : ", cmd, buff));
		cmd_formated = ft_cmd_format(buff, path);
		free(path);
		if (!cmd_formated)
			return (ft_error("Malloc fail : ", cmd, buff));
		if (!access(cmd_formated[0], F_OK))
		{
			free(buff);
			return (cmd_formated);
		}
		ft_freesplit(cmd_formated);
		pathvar += pathlen + 1;
	}
	return (ft_error("Command not found : ", cmd, buff));
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

void	ft_child(char *pathname_in, char **cmd, int fd_in, int fd_tmp)
{
	if (pathname_in && !access(pathname_in, F_OK | R_OK))
		dup2(fd_in, 0);
	dup2(fd_tmp, 1);
	if (execve(cmd[0], cmd, NULL) == -1)
		ft_putstr_fd("Error execve\n", 2);
	close(fd_in);
	close(fd_tmp);
	exit(EXIT_FAILURE);
}

void	ft_cmd_exec(char *pathname_in, char *pathname_out, char **cmd)
{
	pid_t	child_pid;
	int		fd_in;
	int		fd_out;
	int		fd_tmp;

	if (pathname_in && !access(pathname_in, F_OK | R_OK))
		fd_in = open(pathname_in, O_RDONLY | O_CLOEXEC);
	fd_tmp = open(CAT_TMP_FILE, O_WRONLY | O_TRUNC | O_CLOEXEC | O_CREAT, 0644);
	child_pid = fork();
	if (child_pid == 0)
		ft_child(pathname_in, cmd, fd_in, fd_tmp);
	else
	{
		waitpid(child_pid, NULL, 0);
		close(fd_in);
		fd_tmp = open(CAT_TMP_FILE, O_RDONLY);
		fd_out = open(pathname_out, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (ft_cat_fd(fd_tmp, fd_out) == -1)
			ft_error("cattmp error", NULL, NULL);
		close(fd_tmp);
		close(fd_out);
		if (unlink(CAT_TMP_FILE))
			ft_error("Error deletion tmp file (ft_cat)", NULL, NULL);
	}
}
