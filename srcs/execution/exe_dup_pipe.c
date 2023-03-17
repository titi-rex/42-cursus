/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_dup_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:10:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/17 15:26:54 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_dup_pipe(int pipe_in[2], int pipe_out[2])
{
	if (pipe_in[0] != -1)
	{
		if (dup2(pipe_in[0], 0) == -1)
			perror("Error ");
	}
	if (pipe_out[1] != -1)
	{
		if (dup2(pipe_out[1], 1) == -1)
			perror("Error ");
	}
	ft_close_pipe(pipe_in);
	ft_close_pipe(pipe_out);
}
