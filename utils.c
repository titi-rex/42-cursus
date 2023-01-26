/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:35:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/26 14:37:59 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief display error message on stderr depending of errstr or errnum
 * 
 * @param errnum error value for strerror()
 * @param errstr error message to display
 */
void	ft_error(char *errstr, char **cmd)
{
	ft_putstr_fd("Error\n", 2);
	perror(errstr);
	if (cmd)
		ft_freesplit(cmd);
	if (unlink(PIPEX_TMP_FILE))
			ft_putstr_fd("Error deletion tmp file (pipex)\n", 2);
	exit(EXIT_FAILURE);
}
