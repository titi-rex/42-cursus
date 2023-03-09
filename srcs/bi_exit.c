/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:10:12 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/09 16:43:24 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*	TODO: add clean struct	*/
int	bi_exit(t_line *line)
{
	int	exit_code;

	if (line->cmd && line->cmd->arg && line->cmd->arg[1])
		exit_code = ft_atoi(line->cmd->arg[1]);
	else
		exit_code = line->exit_status;
	ft_clear_line(line);
	exit(exit_code);
	return (EXIT_FAILURE);
}
