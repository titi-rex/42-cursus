/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:28:28 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/17 19:35:02 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	bi_export_name_is_valid(char *name)
{
	while (*name)
	{
		if (!ft_isalnum(*name) && *name != '_')
			return (1);
		name++;
	}
	return (0);
}

int	bi_export(t_line *line)
{
	t_var_env	*tmp;

	if (!line->cmd->arg[1])
		return (print_env(line->lst_env));
	if (bi_export_name_is_valid(line->cmd->arg[1]))
		return (ft_error_return("Not a valid identifier "));
	if (!line->cmd->arg[2])
		return (EXIT_SUCCESS);
	tmp = ft_var_env_search(line->lst_env, line->cmd->arg[1]);
	if (tmp)
	{
		free(tmp->value);
		tmp->value = ft_strdup(line->cmd->arg[2]);
		if (!tmp->value)
			return (ft_perror_return_int(NULL));
		//ft_env_update(&line->env, line->lst_env);
		return (EXIT_SUCCESS);
	}
	tmp = ft_new_env(line->cmd->arg[1], line->cmd->arg[2]);
	if (!tmp)
		return (ft_perror_return_int(NULL));
	ft_envadd_back(&line->lst_env, tmp);
	//ft_env_update(&line->env, line->lst_env);
	return (EXIT_SUCCESS);
}
