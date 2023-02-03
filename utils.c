/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:35:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/03 16:43:52 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_error(char *errstr, char *cmdname,char *tofree)
{
	ft_putstr_fd("Error\n", 2);
	if (cmdname)
	{	
		ft_putstr_fd(errstr, 2);
		ft_putendl_fd(cmdname, 2);
	}
	else
		ft_putendl_fd(errstr, 2);
	if (tofree)
		free(tofree);
	return (NULL);
}
