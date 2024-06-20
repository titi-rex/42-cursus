/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_titi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:35:47 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/27 16:55:30 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_titi(t_line *line)
{
	if (printf(CYAN"zzz...\n" END) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
	(void)line;
}
