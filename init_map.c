/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:16:51 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/20 17:32:31 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_count(int count[3])
{
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
}

void	ft_check_path(t_map *map, int count[2])
{
	ft_backtrack(map, 1, 1, count);
	if (count[0] == 0 && count[1] == 0)
		return ;
	ft_error(map, 3, "Map : No path found\n");
}

void	ft_init_map(t_map *map, char *pathname)
{
	int	collectible[2];

	map->layout = ft_get_map(pathname);
	ft_get_mapsize(map);
	ft_init_count(map->count);
	ft_check_map(map);
	collectible[0] = map->count[1];
	collectible[1] = 1;
	ft_check_path(map, collectible);
}
