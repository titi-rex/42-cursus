/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:40:32 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/20 16:40:07 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_map *map, int errnum, char *errstr)
{
	if (map)
	{
		if (map->layout)
			ft_freesplit(map->layout);
	}
	write(2, "Error\n", 6);
	if (!errstr)
		ft_putstr_fd(strerror(errnum), 2);
	else
		ft_putstr_fd(errstr, 2);
	exit(errnum);
}

void	ft_print_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->ysize)
	{
		x = 0;
		while (x < map->xsize)
		{
			ft_printf("%c ", map->layout[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}
