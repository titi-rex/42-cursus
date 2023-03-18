/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:23:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/18 15:51:37 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_lst_env_std(t_var_env **lst)
{
	t_var_env	*new;
	char		*pwd;

	new = NULL;
	new = ft_new_env("SHLVL", "1");
	ft_envadd_back(lst, new);
	pwd = getcwd(NULL, 0);
	if (!pwd)
		new = ft_new_env("PWD", "");
	else
	{
		new = ft_new_env("PWD", pwd);
		free(pwd);
	}
	ft_envadd_back(lst, new);
}

void	envadd(char *env, t_var_env **lst)
{
	char		*name;
	char		*value;
	int			i;
	t_var_env	*new;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	name = ft_strndup(env, i);
	value = ft_strndup(env + i + 1, ft_strlen2(env) - i);
	new = ft_new_env(name, value);
	free(name);
	free(value);
	if (!new)
		return ((void)ft_envclear(&new));
	ft_envadd_back(lst, new);
}

void	fill_lst_env2(t_var_env **lst, char **env)
{
	int			i;

	if (!env || !*env)
		return ((void) fill_lst_env_std(lst));
	i = 0;
	while (env[i])
	{
		envadd(env[i], lst);
		i++;
	}
	ft_var_env_update_shlvl(*lst);
}
