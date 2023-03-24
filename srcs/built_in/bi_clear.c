/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:35:06 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/24 15:39:59 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_clear(t_line *line)
{
	if (printf(CLEAR CURSOR) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
	(void)line;
}
