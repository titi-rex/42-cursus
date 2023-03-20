/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_git.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:51:52 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/20 17:01:58 by tlegrand         ###   ########.fr       */
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
char	*ft_extract_branch(char *dir)
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
		return (ft_perror_return_null(NULL));
	free(head);
	ft_bzero(branch, 1024);
	if (read(fd, &branch, 1024) == -1)
	{
		close(fd);
		return (ft_perror_return_null(NULL));
	}
	close(fd);
	buf = ft_strrchr(branch, '/');
	if (buf)
		buf++;
	return (ft_strndup(buf, ft_strlen2(buf) - 1));
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
char	*ft_get_git_status(void)
{
	int		git_status;
	char	*path_dir_git;
	char	*branche;
	char	*tmp;

	path_dir_git = ft_get_path_dir_git();
	if (!path_dir_git)
		return (NULL);
	git_status = 0;
	if (ft_exist(path_dir_git, "/objects"))
		git_status = 1;
	if (ft_exist(path_dir_git, "/refs"))
		git_status = 1;
	if (ft_exist(path_dir_git, "/HEAD"))
		git_status = 2;
	tmp = ft_extract_branch(path_dir_git);
	if (git_status == 0)
		branche = ft_strjoin3(" on "CYAN"{", tmp, \
			"}"END);
	else if (git_status == 1)
		branche = ft_strdup(" on "RED_LIGH"{detached}"END);
	free(tmp);
	free(path_dir_git);
	return (branche);
}
