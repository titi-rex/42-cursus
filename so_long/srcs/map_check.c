/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:53 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/18 12:36:32 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief check is char is authorized and count number of (starting) Position, 
 * Collectible and Exit
 * 
 * @param c char to check
 * @param count count of E C P char
 * @return int Error 1 // Ok 0
 */
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

/**
 * @brief check the number of starting Position, Collectible and Exit
 * if there isn't expected number of each, display error and exit
 * 
 * @param map map to check
 */
void	ft_check_count(t_map *map)
{
	if (map->count[0] < 1)
		ft_error_map(map, 3, "Map : No starting position\n");
	else if (map->count[0] > 1)
		ft_error_map(map, 3, "Map : Too much starting position\n");
	if (map->count[2] < 1)
		ft_error_map(map, 3, "Map : No exit\n");
	else if (map->count[2] > 1)
		ft_error_map(map, 3, "Map : Too much exit\n");
	if (map->count[1] < 1)
		ft_error_map(map, 3, "Map : No collectible\n");
}

/**
 * @brief check if map is surrounded by wall, if char are legit and call 
 * ft_chech_count
 * if error occur, display error message and quit
 * 
 * @param map 
 */
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
				ft_error_map(map, 3, "Map : Non-valid character in map\n");
			if (y == 0 || x == 0 || y == map->ysize - 1 || x == map->xsize - 1)
			{
				if (map->layout[y][x] != '1')
					ft_error_map(map, 5, "Map : Not surrounded by wall\n");
			}
			x++;
		}
		y++;
	}
	ft_check_count(map);
}

/**
 * @brief recursive backtracking function, try to find a path between P, C and E
 * count down the number of item found
 * 
 * @param map map to check
 * @param ypos 
 * @param xpos 
 */
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

void	ft_map_check_name(char *pathname)
{
	int	i;

	i = 0;
	while (pathname[i])
	{
		if (!ft_strncmp(&pathname[i], ".ber", 5))
			return ;
		i++;
	}
	ft_error_map(NULL, 0, "Wrong argument, so_long only take .ber map\n");
}
