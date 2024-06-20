/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:33:16 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/23 14:02:28 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_move_authorize_player(t_map *map, int pos[2], int axis, int dir)
{
	int	tmp[2];

	tmp[0] = pos[0];
	tmp[1] = pos[1];
	tmp[axis] += dir;
	if (map->layout[tmp[0]][tmp[1]] == '1')
		return (1);
	if (map->layout[tmp[0]][tmp[1]] == 'E' && map->count[1] != 0)
		return (1);
	return (0);
}

void	ft_curtains(t_game_data *game, void *id, t_sprite *end)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.ysize)
	{
		j = 0;
		while (j < game->map.xsize)
		{
			if (i == game->pos[0] && j == game->pos[1])
				ft_display_tile(&game->mlx, end, j, i);
			else
				mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, id, \
					j * TILE, i * TILE);
			j++;
		}
		i++;
	}
}

void	ft_move(t_game_data *game, int axis, int dir)
{
	if (ft_move_authorize_player(&game->map, game->pos, axis, dir))
		return ;
	if (game->map.layout[game->pos[0]][game->pos[1]] == 'E')
		ft_display_tile(&game->mlx, &game->exit, game->pos[1], game->pos[0]);
	else
		ft_display_tile(&game->mlx, &game->floor, game->pos[1], game->pos[0]);
	game->pos[axis] += dir;
	if (axis == 1 && dir == 1)
		ft_animate_run(game, game->run_r, -1);
	else if (axis == 1 && dir == -1)
		ft_animate_run(game, game->run_l, 1);
	else if (axis == 0 && dir == -1)
		ft_animate_jump(game, game->jump, 1);
	else if (axis == 0 && dir == 1)
		ft_animate_jump(game, game->jump, -1);
	ft_map_update(game, game->pos);
	game->move++;
	ft_display_move(game);
	if (game->badguys)
		ft_select_move_enemy(game);
}
