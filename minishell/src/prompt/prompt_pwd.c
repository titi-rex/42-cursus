/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:53:05 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/28 15:44:08 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*prompt_pwd_prettyfy(char *pwd, char *home)
{
	char	*ptr_home;
	char	*ptr_cwd;
	int		count;

	ptr_cwd = ft_strrchr(pwd, '/');
	ptr_home = ft_strnstr(pwd, home, ft_strlen(pwd));
	if (ptr_home)
	{
		ptr_home += ft_strlen(home);
		count = ft_count_char(ptr_home, '/');
		if (count <= 3)
			return (ft_strjoin3(" in "BOLD YELLOW ITALIC"~", ptr_home, END));
		return (ft_strjoin3(" in "BOLD YELLOW ITALIC"~/...", ptr_cwd, END));
	}
	ptr_home = ft_strchr(pwd, '/');
	if (!ptr_home)
		return (NULL);
	count = ft_count_char(ptr_home, '/');
	if (count <= 3)
		return (ft_strjoin3(" in "BOLD YELLOW ITALIC"/", ptr_home, END));
	return (ft_strjoin3(" in "BOLD YELLOW ITALIC"/...", ptr_cwd, END));
}

char	*prompt_pwd(char *user)
{
	char	*username;
	char	*pwd;
	char	*pretty_pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (NULL);
	if (*pwd == '/' && *(pwd + 1) == '\0')
	{
		ft_free_secure(pwd);
		return (ft_strdup(BOLD YELLOW ITALIC" in /"END));
	}
	if (user && user[0] != '/')
		username = ft_strjoin("/", user);
	else if (user)
		username = ft_strdup(user);
	if (!user || !username)
		pretty_pwd = prompt_pwd_prettyfy(pwd, "/home");
	else
	{
		pretty_pwd = prompt_pwd_prettyfy(pwd, username);
		free(username);
	}
	ft_free_secure(pwd);
	return (pretty_pwd);
}
