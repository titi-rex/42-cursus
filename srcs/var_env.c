/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:58:48 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/11 13:25:09 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	fill_lst_env(t_line *line, int i)
{
	char		*name;
	char		*value;
	int			n;
	t_var_env	*new;

	new = NULL;
	line->lst_env = new;
	while (line->env[i])
	{
		n = 0;
		while (line->env[i][n] && line->env[i][n] != '=')
			n++;
		name = ft_strndup(line->env[i], n);
		value = ft_strndup(line->env[i] + n + 1, ft_strlen2(line->env[i]) - n);
		new = ft_new_env(name, value);
		free(name);
		free(value);
		if (!new)
			return ((void)ft_envclear(&line->lst_env));
		ft_envadd_back(&line->lst_env, new);
		i++;
	}
}

int	print_env(t_var_env	*lst)
{
	int	err;

	err = EXIT_SUCCESS;
	while (lst)
	{
		if (printf("%s = %s\n", lst->name, lst->value) < 0)
			err = EXIT_FAILURE;
		lst = lst->next;
	}
	return (err);
}

t_var_env	*ft_var_env_search(t_var_env *lst, char *name)
{
	while (lst)
	{
		if (ft_strncmp(lst->name, name, ft_strlen2(name) + 1))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
