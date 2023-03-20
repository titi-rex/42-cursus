/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:53:05 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/20 17:33:14 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_prettyfy_pwd(char *pwd, char *home)
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
			return (ft_strjoin3(BOLD YELLOW ITALIC"~", ptr_home, END));
		return (ft_strjoin3(BOLD YELLOW ITALIC"~/...", ptr_cwd, END));
	}
	ptr_home = ft_strchr(pwd, '/');
	count = ft_count_char(ptr_home, '/');
	if (count <= 3)
		return (ft_strjoin3(BOLD YELLOW ITALIC, ptr_home, END));
	return (ft_strjoin3(BOLD YELLOW ITALIC"/...", ptr_cwd, END));
}

char	*ft_get_pwd(char *pwd, char *user)
{
	char	*username;
	char	*pretty_pwd;

	if (!pwd)
		pwd = getcwd(NULL, 0);
	if (!pwd)
		return (NULL);
	if (*pwd == '/' && *(pwd + 1) == '\0')
		return (ft_strdup(BOLD YELLOW ITALIC"/"END));
	if (user && user[0] != '/')
		username = ft_strjoin("/", user);
	else if (user)
		username = ft_strdup(user);
	if (!user || !username)
		pretty_pwd = ft_prettyfy_pwd(pwd, "/home");
	else
	{
		pretty_pwd = ft_prettyfy_pwd(pwd, username);
		free(username);
	}
	return (pretty_pwd);
}
