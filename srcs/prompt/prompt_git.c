/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_git.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:51:52 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/26 21:08:03 by tlegrand         ###   ########.fr       */
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
static char	*ft_exist(char *dir, char *target)
{
	char	*tmp;

	tmp = ft_strjoin(dir, target);
	if (!access(tmp, F_OK))
		return (tmp);
	free(tmp);
	return (NULL);
}

/**
 * @brief extract current branch name given a git dir 
 * 
 * @param dir the .git dir
 * @return char* current branch name or NULL 
 */
static char	*prompt_git_extract_branch(char *dir)
{
	char	branch[1024];
	char	*head;
	char	*buf;
	int		fd;

	head = ft_strjoin(dir, "/HEAD");
	if (!head)
		return (NULL);
	fd = open(head, O_RDONLY);
	free(head);
	if (fd == -1)
		return (perror("Error "), NULL);
	ft_bzero(branch, 1024);
	if (read(fd, &branch, 1024) == -1)
	{
		close(fd);
		return (perror("Error "), NULL);
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
static char	*prompt_git_get_path_dir(void)
{
	char	*path_dir_git;
	char	*pwd;
	int		i;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (NULL);
	path_dir_git = ft_strnstr(pwd, "/.git", ft_strlen(pwd));
	if (path_dir_git)
		return (ft_strndup(pwd, ft_strlen(pwd) - ft_strlen(path_dir_git) + 5));
	i = 0;
	while (i++ < 3 && pwd)
	{
		path_dir_git = ft_exist(pwd, "/.git");
		if (path_dir_git)
		{
			free(pwd);
			return (path_dir_git);
		}
		if (path_dir_git)
			free(path_dir_git);
		pwd = ft_strerase_end(pwd, ft_strrchr(pwd, '/'));
	}
	free(pwd);
	return (NULL);
}

static int	prompt_git_status(char *pgd)
{
	char	*tmp;
	int		status;

	status = 0;
	tmp = ft_exist(pgd, "/objects");
	if (!tmp)
		status = 1;
	else
		free(tmp);
	tmp = ft_exist(pgd, "/refs");
	if (!tmp)
		status = 1;
	else
		free(tmp);
	tmp = ft_exist(pgd, "/HEAD");
	if (!tmp)
		status = 2;
	else
		free(tmp);
	return (status);
}

/**
 * @brief search for a .git repo inside pwd, attach name of current branch 
 * 	and return status of git repo 
 * 
 * @param current_branche ptr to branch name, must be initialised to NULL before
 * @return int 0 : git ok, 1 detached state, 2 no git repo or repo broken
 */
char	*prompt_git(void)
{
	int		git_status;
	char	*pgd;
	char	*branche;
	char	*tmp;

	tmp = NULL;
	branche = NULL;
	pgd = prompt_git_get_path_dir();
	if (!pgd)
		return (NULL);
	git_status = prompt_git_status(pgd);
	if (git_status == 0)
	{
		tmp = prompt_git_extract_branch(pgd);
		branche = ft_strjoin3(" on "CYAN"{", tmp, "}"END);
		free(tmp);
	}
	else if (git_status == 1)
		branche = ft_strdup(" on "RED"{detached}"END);
	free(pgd);
	return (branche);
}
