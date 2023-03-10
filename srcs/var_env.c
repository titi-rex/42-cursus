/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:58:48 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/10 13:44:46 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strndup(char *src, int n)
{
	int		tmp;
	char	*cpy;

	cpy = (char *)malloc((n + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	tmp = 0;
	while (src && src[tmp] && tmp < n)
	{
		cpy[tmp] = src[tmp];
		tmp++;
	}
	cpy[tmp] = '\0';
	return (cpy);
}

void	init_variables(t_var_env *lst)
{
	lst->name = NULL;
	lst->value = NULL;
	lst->next = NULL;
	lst->previous = NULL;
}

void	fill_lst_env(t_line *line)
{
	char		*name;
	char		*value;
	int			i;
	int			n;
	t_var_env	*lst;
	t_var_env	*new;

	i = 0;
	new = NULL;
	lst = new;
	while (line->env[i])
	{
		if (ft_strchr(line->env[i], '='))
			n = ft_strchr(line->env[i], '=') - line->env[i];
		else
			n = 0;
		name = ft_strndup(line->env[i], n);
		value = ft_strndup(line->env[i] + n + 1, \
				ft_strchr(line->env[i] + n + 1, '\0') \
					- (line->env[i] + n + 1));
		new = ft_new_env(name, value);
		if (!new)
			return ;
		ft_envadd_back(&lst, new);
		free(name);
		free(value);
		i++;
	}
}

//ft_strlen pas le bon