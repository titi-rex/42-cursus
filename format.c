/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:25:56 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/06 17:16:18 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_cmd_search(char *cmd, char *pathvar)
{
	char	*path;
	char	**cmd_formated;
	int		pathlen;

	while (*pathvar != '/')
		pathvar++;
	while (*pathvar == '/')
	{
		pathlen = ft_pathlen(pathvar);
		path = ft_substr(pathvar, 0, pathlen);
		if (!path)
			return (ft_error("Malloc fail : ", cmd, NULL));
		cmd_formated = ft_cmd_format(cmd, path);
		free(path);
		if (!cmd_formated)
			return (ft_error("Malloc fail : ", cmd, NULL));
		if (!access(cmd_formated[0], F_OK))
			return (cmd_formated);
		ft_freesplit(cmd_formated);
		pathvar += pathlen + 1;
	}
	return (ft_error("Command not found : ", cmd, NULL));
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
	if (!access(pathname_in, F_OK | R_OK))
	{
		dup2(fd_in, 0);
		dup2(fd_tmp, 1);
		if (execve(cmd[0], cmd, NULL) == -1)
			ft_putstr_fd("Error execve\n", 2);
	}
	else
		ft_error("Input file not found", NULL, NULL);
	close(fd_in);
	close(fd_tmp);
	exit(EXIT_FAILURE);
}

void	ft_parent(char *pathname_out, int fd_in, int child_pid)
{
	int	fd_out;
	int	fd_tmp;

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

void	ft_cmd_exec(char *pathname_in, char *pathname_out, char **cmd)
{
	pid_t	child_pid;
	int		fd_in;
	int		fd_tmp;

	if (!access(pathname_in, F_OK | R_OK))
		fd_in = open(pathname_in, O_RDONLY | O_CLOEXEC);
	fd_tmp = open(CAT_TMP_FILE, O_WRONLY | O_TRUNC | O_CLOEXEC | O_CREAT, 0644);
	if (fd_in == -1 || fd_tmp == -1)
		return ((void) ft_error("Open failed", cmd[0], NULL));
	child_pid = fork();
	if (child_pid == 0)
		ft_child(pathname_in, cmd, fd_in, fd_tmp);
	else
		ft_parent(pathname_out, fd_in, child_pid);
}
