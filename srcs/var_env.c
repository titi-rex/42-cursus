/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:58:48 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/10 14:27:20 by lboudjem         ###   ########.fr       */
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
			return ;
		ft_envadd_back(&line->lst_env, new);
		i++;
	}
}

void	print_env(t_var_env	*lst)
{
	while (lst)
	{
		ft_putstr_fd(lst->name, 1);
		ft_putchar_fd('=', 1);
		ft_putstr_fd(lst->value, 1);
		ft_putchar_fd('\n', 1);
		lst = lst->next;
	}
}
