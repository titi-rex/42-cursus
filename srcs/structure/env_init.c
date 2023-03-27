/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:23:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/27 14:08:47 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_env_init_std(t_var_env **lst)
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

static void	ft_env_init_add(char *env, t_var_env **lst)
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

void	ft_env_init(t_var_env **lst, char **env)
{
	int			i;

	if (!env || !*env)
		return ((void) ft_env_init_std(lst));
	i = 0;
	while (env[i])
	{
		ft_env_init_add(env[i], lst);
		i++;
	}
	ft_env_update_shlvl(*lst);
}
