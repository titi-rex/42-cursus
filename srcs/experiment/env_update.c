/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:23:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/15 16:31:56 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_var_env	*fill_lst_env2(char **env, int i)
{
	char		*name;
	char		*value;
	int			n;
	t_var_env	*new;

	new = NULL;
	while (env[i])
	{
		n = 0;
		while (env[i][n] && env[i][n] != '=')
			n++;
		name = ft_strndup(env[i], n);
		value = ft_strndup(env[i] + n + 1, ft_strlen2(env[i]) - n);
		new = ft_new_env(name, value);
		free(name);
		free(value);
		if (!new)
			return (ft_envclear(&new), NULL);
		ft_envadd_back(&new, new);
		i++;
	}
	return (new);
}
