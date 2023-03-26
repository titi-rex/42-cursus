/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:01:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/26 13:55:50 by tlegrand         ###   ########.fr       */
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
	pwd = prompt_pwd(ft_env_get_value(lst_env, "PWD"), \
		ft_env_get_value(lst_env, "USER"));
	username = prompt_username(ft_env_get_value(lst_env, "USER"));
	tmp = ft_strjoin3(username, pwd, git);
	if (!exit_status)
		prompt = ft_strjoin3(tmp, GREEN BOLD" (*o*) "END, PURPLE"-$> "END);
	else
		prompt = ft_strjoin3(tmp, RED" (~.~) "END, PURPLE"-$> "END);
	if (tmp)
		free(tmp);
	if (git)
		free(git);
	if (pwd)
		free(pwd);
	if (username)
		free(username);
	return (prompt);
}
