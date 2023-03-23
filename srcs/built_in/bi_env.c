/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:06:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/23 12:34:56 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	bi_env_print(t_var_env	*lst)
{
	int	err;

	err = EXIT_SUCCESS;
	while (lst)
	{
		if (lst->value)
			if (printf("%s=%s\n", lst->name, lst->value) < 0)
				err = EXIT_FAILURE;
		lst = lst->next;
	}
	return (err);
}

int	bi_env(t_line *line)
{
	if (line->cmd->arg[1])
	{
		ft_putendl_fd("Error : env take no options nor arguments", 2);
		return (EXIT_FAILURE);
	}
	return (bi_env_print(line->lst_env));
}
