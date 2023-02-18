/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:16:51 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/18 12:38:53 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_path(t_map *map)
{
	ft_backtrack(map, 1, 1);
	if (map->count[1] == 0 && map->count[2] == 0)
		return (1);
	return (0);
}

void	ft_mapcpy(t_map *src, t_map *dst)
{
	int	y;

	dst->ysize = src->ysize;
	dst->xsize = src->xsize;
	dst->layout = (char **)ft_calloc(dst->ysize + 1, sizeof(char *));
	if (!dst->layout)
		ft_error_map(src, 12, NULL);
	y = 0;
	while (y < dst->ysize)
	{
		dst->layout[y] = ft_strdup(src->layout[y]);
		if (!dst->layout[y])
		{
			ft_free2d((void **) dst->layout, 0);
			ft_error_map(src, 12, NULL);
		}
		y++;
	}
	dst->count[0] = src->count[0];
	dst->count[1] = src->count[1];
	dst->count[2] = src->count[2];
}

/**
 * @brief fill map from file and check if map is legit
 * (i.e map rectangular, no non-valid char, path exist, 
 * only 1 exit and starting pos, at least 1 collectible, 
 * map closed by wall) 
 * if error occur, display error message and quit
 * 
 * @param map map to initialize
 * @param pathname pathname of the file
 */
void	ft_init_map(t_map *map, char *pathname)
{
	t_map	cpy;

	ft_map_check_name(pathname);
	map->layout = ft_get_map(pathname);
	ft_get_mapsize(map);
	map->count[0] = 0;
	map->count[1] = 0;
	map->count[2] = 0;
	ft_check_map(map);
	ft_mapcpy(map, &cpy);
	if (!ft_check_path(&cpy))
	{
		ft_free2d((void **) cpy.layout, 0);
		ft_error_map(map, 3, "Map : No path found\n");
	}
	ft_free2d((void **) cpy.layout, 0);
}
