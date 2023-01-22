/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:35:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/22 17:35:19 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief display error message on stderr depending of errstr or errnum
 * 
 * @param errnum error value for strerror()
 * @param errstr error message to display
 */
void	ft_error(char *errstr)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(errstr, 2);
	exit(EXIT_FAILURE);
}

size_t	ft_intlen(int n)
{
	int	len;

	len = 1;
	while (n > 1)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	debug_command(int pid, int wit)
{
	if (wit == 1)
	{
		if (kill(pid, SIGTERM) == -1)
			ft_error("Fail to require server's shutdown\n");
		exit(EXIT_SUCCESS);
	}
	if (wit == 2)
	{
		if (kill(pid, SIGFPE) == -1)
			ft_error("Fail to ask statue of g_bin to server\n");
		exit(EXIT_SUCCESS);
	}
}
