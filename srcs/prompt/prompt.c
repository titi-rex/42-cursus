/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:01:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/28 16:23:53 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*prompt_username(char *user)
{
	char	*username;

	if (!user)
		return (ft_strdup(PURPLE"guest"END));
	username = ft_strjoin3(PURPLE, user, END);
	if (!username)
		username = ft_strdup(PURPLE"guest"END);
	return (username);
}

char	*ft_get_a_nice_prompt(t_var_env *lst_env, int exit_status)
{
	char	*username;
	char	*pwd;
	char	*git;
	char	*prompt;
	char	*tmp;

	git = prompt_git();
	pwd = prompt_pwd(env_get_value(lst_env, "USER"));
	username = prompt_username(env_get_value(lst_env, "USER"));
	tmp = ft_strjoin3(username, pwd, git);
	if (!exit_status)
		prompt = ft_strjoin3(tmp, GREEN BOLD" (*o*) "END, PURPLE"-$> "END);
	else
		prompt = ft_strjoin3(tmp, RED" (~.~) "END, PURPLE"-$> "END);
	ft_free_secure(tmp);
	ft_free_secure(git);
	ft_free_secure(pwd);
	ft_free_secure(username);
	return (prompt);
}
