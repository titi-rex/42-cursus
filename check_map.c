/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:53 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/20 20:45:21 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_is_valid(char c, int count[3])
{
	if (c == '1' || c == '0')
		return (0);
	else if (c == 'P')
	{
		count[0]++;
		return (0);
	}
	else if (c == 'C')
	{
		count[1]++;
		return (0);
	}
	else if (c == 'E')
	{
		count[2]++;
		return (0);
	}
	return (1);
}

void	ft_check_count(t_map *map, int count[3])
{
	if (count[0] < 1)
		ft_error(map, 3, "Map : No starting position\n");
	else if (count[0] > 1)
		ft_error(map, 3, "Map : Too much starting position\n");
	if (count[2] < 1)
		ft_error(map, 3, "Map : No exit\n");
	else if (count[2] > 1)
		ft_error(map, 3, "Map : Too much exit\n");
	if (count[1] < 1)
		ft_error(map, 3, "Map : No collectible\n");
}

void	ft_check_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->ysize)
	{
		x = 0;
		while (x < map->xsize)
		{
			if (ft_is_valid(map->layout[y][x], map->count))
				ft_error(map, 3, "Map : Non-valid character in map\n");
			if (y == 0 || x == 0 || y == map->ysize - 1 || x == map->xsize - 1)
			{
				if (map->layout[y][x] != '1')
					ft_error(map, 5, "Map : Not surrounded by wall\n");
			}
			x++;
		}
		y++;
	}
	ft_check_count(map, map->count);
}

void	ft_backtrack(t_map *map, int ypos, int xpos)
{
	if (map->layout[ypos][xpos] == 'C')
		map->count[1]--;
	if (map->layout[ypos][xpos] == 'E')
		map->count[2]--;
	map->layout[ypos][xpos] = '1';
	if (map->count[1] == 0 && map->count[2] == 0)
		return ;
	if (map->layout[ypos + 1][xpos] != '1')
		ft_backtrack(map, ypos + 1, xpos);
	if (map->layout[ypos][xpos + 1] != '1')
		ft_backtrack(map, ypos, xpos + 1);
	if (map->layout[ypos - 1][xpos] != '1')
		ft_backtrack(map, ypos - 1, xpos);
	if (map->layout[ypos][xpos - 1] != '1')
		ft_backtrack(map, ypos, xpos - 1);
}
