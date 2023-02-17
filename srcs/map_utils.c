/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:40:32 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/17 12:59:29 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_clean_map(t_map *map)
{
	if (map)
	{
		if (map->layout)
			ft_free2d((void **) map->layout, 0);
	}
}

void	ft_error_map(t_map *map, int errnum, char *errstr)
{
	ft_clean_map(map);
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
