/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:06:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/15 13:26:25 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_unset(t_line *line)
{
	t_var_env	*tmp;

	if (!line->cmd->arg[1])
		return (EXIT_SUCCESS);
	tmp = ft_var_env_search(line->lst_env, line->cmd->arg[1]);
	if (!tmp)
		return (EXIT_SUCCESS);
	ft_envremove(tmp);
	//ft_env_update(&line->env, line->lst_env);
	return (EXIT_SUCCESS);
}
