/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:23:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/29 16:23:06 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_update_shlvl(t_var_env *lst)
{
	t_var_env	*tmp;
	char		*buff;
	int			lvl;

	tmp = env_search(lst, "SHLVL");
	if (!tmp)
		return ;
	lvl = ft_atoi(tmp->value);
	lvl += 1;
	buff = ft_itoa(lvl);
	if (!buff)
		return (perror("Error "));
	env_change_value(lst, buff, "SHLVL");
	free(buff);
}

static int	env_init_add(char *env, t_var_env **lst)
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
	if (!value)
		return (ft_free_secure(name), 1);
	new = s_env_new(name, value);
	ft_free_secure(name);
	ft_free_secure(value);
	if (!new)
		return (1);
	s_env_add_back(lst, new);
	return (0);
}

static char	*env_get_pwd(void)
{
	char	*pwd;
	char	*tmp;

	tmp = getcwd(NULL, 0);
	if (!tmp)
		return (NULL);
	pwd = ft_strjoin("PWD=", tmp);
	free(tmp);
	return (pwd);
}

int	env_init(t_var_env **lst, char **env)
{
	char	*pwd;
	int		i;

	i = -1;
	while (env[++i])
	{
		if (env_init_add(env[i], lst))
			return (s_env_clear(lst), 1);
	}
	if (!env_search(*lst, "SHLVL"))
		env_init_add("SHLVL=1", lst);
	else
		env_update_shlvl(*lst);
	if (!env_search(*lst, "PWD"))
	{
		pwd = env_get_pwd();
		if (pwd)
		{
			env_init_add(pwd, lst);
			free(pwd);
		}
		else
			env_init_add("PWD=", lst);
	}
	return (0);
}
