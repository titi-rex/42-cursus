/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:06:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/28 12:52:00 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_unset(t_line *line)
{
	t_var_env	*tmp;

	if (!line->cmd->arg[1])
		return (EXIT_SUCCESS);
	tmp = ft_env_search(line->lst_env, line->cmd->arg[1]);
	if (!tmp)
		return (EXIT_SUCCESS);
	s_env_remove(&line->lst_env, tmp);
	exe_envtab_update(&line->env, line->lst_env);
	return (EXIT_SUCCESS);
}
