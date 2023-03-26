/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:23:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/26 12:09:44 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_fill_lst_std(t_var_env **lst)
{
	t_var_env	*new;
	char		*pwd;

	new = NULL;
	new = ft_env_new("SHLVL", "1");
	ft_env_add_back(lst, new);
	pwd = getcwd(NULL, 0);
	if (!pwd)
		new = ft_env_new("PWD", "");
	else
	{
		new = ft_env_new("PWD", pwd);
		free(pwd);
	}
	ft_env_add_back(lst, new);
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
	new = ft_env_new(name, value);
	free(name);
	free(value);
	if (!new)
		return ((void)ft_env_clear(&new));
	ft_env_add_back(lst, new);
}

void	ft_env_fill_lst2(t_var_env **lst, char **env)
{
	int			i;

	if (!env || !*env)
		return ((void) ft_env_fill_lst_std(lst));
	i = 0;
	while (env[i])
	{
		envadd(env[i], lst);
		i++;
	}
	ft_env_update_shlvl(*lst);
}
