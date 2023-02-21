/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:25:43 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/21 01:02:09 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_randint(int min, int max)
{
	int	fd;
	int	c;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return (0);
	read(fd, &c, 1);
	close (fd);
	return (c % max + min);
}

void	ft_init_enemy_secure(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->ysize)
	{
		j = 0;
		while (j < map->xsize)
		{
			if (map->layout[i][j] == '0')
				map->layout[i][j] = 'E';
			j++;
		}
		i++;
	}
}

void	ft_init_enemy(t_map *map, int *badguys)
{
	int	i;
	int	j;
	int	wit;

	if (!*badguys)
		return ;
	i = 0;
	j = 0;
	wit = 0;
	while (map->layout[i][j] != '0')
	{
		i = ft_randint(1, map->ysize);
		j = ft_randint(1, map->xsize);
		wit++;
		if (wit > 50)
			return ((void) ft_init_enemy_secure(map));
	}
	map->layout[i][j] = 'E';
}
