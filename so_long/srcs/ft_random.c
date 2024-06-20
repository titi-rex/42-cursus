/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:58:43 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/23 13:59:46 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_randuint(int min, int max, int *err)
{
	unsigned int	c;
	int				fd;

	c = 0;
	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		*err = 0;
	else
	{
		if (read(fd, &c, 1) == -1)
			*err = 0;
		close (fd);
	}
	return (c % (max + 1 - min) + min);
}
