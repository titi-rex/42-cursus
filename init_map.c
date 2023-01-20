/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:16:51 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/20 17:08:16 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_count(int count[3])
{
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
}

void	ft_init_map(t_map *map, char *pathname)
{
	int	collectible;

	map->layout = ft_get_map(pathname);
	ft_get_mapsize(map);
	ft_init_count(map->count);
	ft_check_map(map);
	collectible = map->count[1];
//	ft_check_count(map, 1, 1, collectible);
}
