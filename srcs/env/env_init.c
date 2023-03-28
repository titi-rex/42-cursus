/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:23:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/28 12:52:35 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_update_shlvl(t_var_env *lst)
{
	t_var_env	*tmp;
	char		*buff;
	int			lvl;

	tmp = ft_env_search(lst, "SHLVL");
	if (!tmp)
		return ;
	lvl = ft_atoi(tmp->value);
	lvl += 1;
	buff = ft_itoa(lvl);
	if (!buff)
		return (perror("Error "));
	ft_env_change_value(lst, buff, "SHLVL");
	free(buff);
}

static void	ft_env_init_std(t_var_env **lst)
{
	t_var_env	*new;
	char		*pwd;

	new = NULL;
	new = s_env_new("SHLVL", "1");
	s_env_add_back(lst, new);
	pwd = getcwd(NULL, 0);
	if (!pwd)
		new = s_env_new("PWD", "");
	else
	{
		new = s_env_new("PWD", pwd);
		free(pwd);
	}
	s_env_add_back(lst, new);
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
	new = s_env_new(name, value);
	free(name);
	free(value);
	if (!new)
		return ((void)s_env_clear(&new));
	s_env_add_back(lst, new);
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
