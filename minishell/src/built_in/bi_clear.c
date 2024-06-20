/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:35:06 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/29 21:05:13 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_clear(t_line *line)
{
	if (line->cmd->arg[1] && line->cmd->arg[1][0] == '-' && \
		line->cmd->arg[1][1] != '\0')
		return (perror("Error : no option available "), 2);
	if (printf(CLEAR CURSOR) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
