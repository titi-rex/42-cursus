/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:10:12 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/25 12:07:32 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_exit(t_line *line)
{
	int	exit_code;

	if (line->cmd->arg[1] && ft_str_isdigit(line->cmd->arg[1]))
	{
		ft_putstr_fd("exit : ", 2);
		ft_putstr_fd(line->cmd->arg[1], 2);
		ft_putendl_fd(" : numeric arguent needed", 2);
		exit_code = 2;
	}
	else if (line->cmd->arg[1] && line->cmd->arg[2])
	{
		ft_putendl_fd("exit : too much argument", 2);
		return (EXIT_FAILURE);
	}
	else if (line->cmd->arg && line->cmd->arg[1])
		exit_code = ft_atoi(line->cmd->arg[1]);
	else
		exit_code = line->exit_status;
	ft_putendl_fd("exit", 1);
	term_reset(&line->old);
	ft_clean_exit(line, exit_code);
	return (EXIT_FAILURE);
}
