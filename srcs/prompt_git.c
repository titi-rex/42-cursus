/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_git.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:51:52 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/18 22:40:05 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief check if a target file/dir exist inside a given dir
 * 
 * @param dir 
 * @param target 
 * @return int 1 dont exit or cant read it // 0 exist and can be read
 */
int	ft_exist(char *dir, char *target)
{
	char	*tmp;
	int		res;

	tmp = ft_strjoin(dir, target);
	if (access(tmp, F_OK))
		res = 1;
	else
		res = 0;
	free(tmp);
	return (res);
}

/**
 * @brief extract current branch name given a git dir 
 * 
 * @param dir the .git dir
 * @return char* current branch name or NULL 
 */
char	*ft_extract_branche(char *dir)
{
	char	branch[1024];
	char	*head;
	char	*buf;
	int		fd;

	head = ft_strjoin(dir, "/HEAD");
	if (!head)
		return (NULL);
	fd = open(head, O_RDONLY);
	if (fd == -1)
	{
		perror("Error ");
		return (NULL);
	}
	free(head);
	ft_bzero(branch, 1024);
	if (read(fd, &branch, 1024) == -1)
	{
		perror("Error ");
		close(fd);
		return (NULL);
	}
	close(fd);
	buf = ft_strrchr(branch, '/');
	return (ft_strndup(buf, ft_strlen2(buf)));
}

/**
 * @brief look for a .git dir inside pwd 
 * 
 * @return char* .git path or NULL
 */
char	*ft_get_path_dir_git(void)
{
	char	*path_dir_git;
	char	*cwd;
	char	*tmp;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (NULL);
	tmp = ft_strnstr(cwd, ".git", ft_strlen(cwd));
	if (!tmp)
		path_dir_git = ft_strjoin(cwd, "/.git");
	else
		path_dir_git = ft_strndup(cwd, ft_strlen(cwd) - ft_strlen(tmp) + 4);
	free(cwd);
	if (path_dir_git && ft_exist(path_dir_git, NULL))
	{
		free(path_dir_git);
		return (NULL);
	}
	return (path_dir_git);
}

/**
 * @brief search for a .git repo inside pwd, attach name of current branch 
 * 	and return status of git repo 
 * 
 * @param current_branche ptr to branch name, must be initialised to NULL before
 * @return int 0 : git ok, 1 detached state, 2 no git repo or repo broken
 */
int	ft_get_git_status(char **current_branche)
{
	int		git_status;
	char	*path_dir_git;

	path_dir_git = ft_get_path_dir_git();
	if (!path_dir_git)
		return (2);
	git_status = 0;
	if (ft_exist(path_dir_git, "/object"))
		git_status = 1;
	if (ft_exist(path_dir_git, "/refs"))
		git_status = 1;
	if (ft_exist(path_dir_git, "/HEAD"))
		git_status = 2;
	else
		*current_branche = ft_extract_branche(path_dir_git);
	free(path_dir_git);
	return (git_status);
}
