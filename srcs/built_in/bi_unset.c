/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:06:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/29 22:22:53 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_unset(t_line *line)
{
	t_var_env	*tmp;
	int			i;
	int			err;

	if (line->cmd->arg[1] && line->cmd->arg[1][0] == '-' && \
		line->cmd->arg[1][1] != '\0')
		return (perror("Error : no option available "), 2);
	i = 1;
	err = 0;
	while (line->cmd->arg[i])
	{
		tmp = env_search(line->lst_env, line->cmd->arg[i]);
		if (!tmp)
			err = 2;
		else
			s_env_remove(&line->lst_env, tmp);
		i++;
	}
	exe_envtab_update(&line->env, line->lst_env);
	return (err);
}
