/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:16:51 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/20 20:45:54 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_count(int count[3])
{
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
}

void	ft_check_path(t_map *map)
{
	ft_backtrack(map, 1, 1);
	if (map->count[1] == 0 && map->count[2] == 0)
		return ;
	ft_error(map, 3, "Map : No path found\n");
}

void	ft_mapcpy(t_map *src, t_map *dst)
{
	int	y;

	dst->ysize = src->ysize;
	dst->xsize = src->xsize;
	dst->layout = (char **)ft_calloc(dst->ysize, sizeof(char *));
	if (!dst->layout)
		ft_error(NULL, 12, NULL);
	y = 0;
	while (y < dst->ysize)
	{
		dst->layout[y] = ft_strdup(src->layout[y]);
		if (!dst->layout[y])
			ft_error(NULL, 12, NULL);
		y++;
	}
	dst->count[0] = src->count[0];
	dst->count[1] = src->count[1];
	dst->count[2] = src->count[2];
}

void	ft_init_map(t_map *map, char *pathname)
{
	t_map	cpy;

	map->layout = ft_get_map(pathname);
	ft_get_mapsize(map);
	ft_init_count(map->count);
	ft_check_map(map);
	ft_mapcpy(map, &cpy);
	ft_check_path(&cpy);
	ft_freesplit(cpy.layout);
}
