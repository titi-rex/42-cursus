/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:10:12 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/08 14:14:53 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*	TODO: add clean struct	*/
void	bi_exit(t_line *line, int exit_status)
{
	if (exit_status != -1)
		exit(exit_status);
	else
		exit(line->exit_status);
}
