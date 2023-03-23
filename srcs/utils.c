/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:43:01 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/23 16:53:08 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_perror_exit(t_line *line, int exit_status, char *errstr)
{
	if (errstr)
		perror(errstr);
	else
		perror("Error ");
	ft_clean_exit(line, exit_status);
}

void	ft_clean_exit(t_line *line, int exit_code)
{
	rl_clear_history();
	s_line_clear(line);
	exit(exit_code);
}
