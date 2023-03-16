/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:10:12 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/16 16:47:17 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_exit(t_line *line)
{
	int	exit_code;

	if (line->cmd && line->cmd->arg && line->cmd->arg[1])
		exit_code = ft_atoi(line->cmd->arg[1]);
	else
		exit_code = line->exit_status;
	ft_putendl_fd("exit", 2);
	ft_clean_exit(line, exit_code);
	return (EXIT_FAILURE);
}
