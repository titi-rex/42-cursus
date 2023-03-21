/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:01:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/21 14:43:18 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_prompt_username(char *user)
{
	char	*username;

	if (!user)
		return (ft_strdup(VIOLET"guest"END));
	username = ft_strjoin3(VIOLET, user, END);
	if (!username)
		username = ft_strdup(VIOLET"guest"END);
	return (username);
}

char	*ft_get_a_nice_prompt(t_var_env *lst_env, int exit_status)
{
	char	*username;
	char	*pwd;
	char	*git;
	char	*prompt;
	char	*tmp;

	git = ft_prompt_git();
	pwd = ft_prompt_pwd(get_value(lst_env, "PWD"), get_value(lst_env, "USER"));
	username = ft_prompt_username(get_value(lst_env, "USER"));
	tmp = ft_strjoin3(username, pwd, git);
	if (!exit_status)
		prompt = ft_strjoin3(tmp, GREEN_L BOLD" (*o*) "END, VIOLET"-$> "END);
	else
		prompt = ft_strjoin3(tmp, RED" (~.~) "END, VIOLET"-$> "END);
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
