/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:25:04 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/07 14:35:15 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_cat_error(char *errstr)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(errstr, 2);
	return (-1);
}

int	ft_cat_fd(int fdin, int fdout)
{
	int		n_read;
	int		n_write;
	char	c;

	n_read = 1;
	while (n_read)
	{		
		n_read = read(fdin, &c, 1);
		if (!n_read)
			break ;
		if (n_read == -1)
			return (ft_cat_error("Read error (ft_cat)\n"));
		n_write = write(fdout, &c, 1);
		if (!n_write)
			return (ft_cat_error("No place to write\n"));
		if (n_write == -1)
			return (ft_cat_error("Write permission denied\n"));
	}
	return (0);
}
