/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:25:43 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/23 14:25:20 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_init_enemy_secure(t_game_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.ysize)
	{
		j = 0;
		while (j < game->map.xsize)
		{
			if (game->map.layout[i][j] == '0')
			{
				game->pos_b[0] = i;
				game->pos_b[1] = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_init_enemy(t_game_data *game)
{
	int	i;
	int	j;
	int	wit;

	if (!game->badguys)
		return ;
	i = 0;
	j = 0;
	wit = 50;
	while (game->map.layout[i][j] != '0')
	{
		i = ft_randuint(1, game->map.ysize - 2, &wit);
		j = ft_randuint(1, game->map.xsize - 2, &wit);
		wit--;
		if (wit <= 0)
			return ((void) ft_init_enemy_secure(game));
	}
	game->pos_b[0] = i;
	game->pos_b[1] = j;
}

int	ft_move_authorize_enemy(t_map *map, int pos[2], int axis, int dir)
{
	int	tmp[2];

	tmp[0] = pos[0];
	tmp[1] = pos[1];
	tmp[axis] += dir;
	if (map->layout[tmp[0]][tmp[1]] == '1' || \
		map->layout[tmp[0]][tmp[1]] == 'E')
		return (1);
	return (0);
}

void	ft_move_enemy(t_game_data *game, int axis, int dir)
{
	if (ft_move_authorize_enemy(&game->map, game->pos_b, axis, dir))
		return ;
	if (game->map.layout[game->pos_b[0]][game->pos_b[1]] == 'E')
		ft_display_tile(&game->mlx, &game->exit, game->pos_b[1], \
			game->pos_b[0]);
	else if (game->map.layout[game->pos_b[0]][game->pos_b[1]] == 'C')
		ft_display_tile(&game->mlx, &game->gem[game->pos_b[1] % 3 + game->pos_b \
			[0] % 3], game->pos_b[1], game->pos_b[0]);
	else
		ft_display_tile(&game->mlx, &game->floor, game->pos_b[1], \
			game->pos_b[0]);
	game->pos_b[axis] += dir;
	ft_display_tile(&game->mlx, &game->enemy[1], game->pos_b[1], \
		game->pos_b[0]);
	ft_is_lost(game);
}


void	ft_select_move_enemy(t_game_data *game)
{
	int	dir;
	int	err;

	if (game->pause)
		return ;
	err = 1;
	dir = ft_randuint(1, 4, &err);
	if (err == 0)
		return ((void) ft_putendl_fd("Randuint for enemy move fail", 2));
	else if (dir == 1)
		ft_move_enemy(game, 0, -1);
	else if (dir == 2)
		ft_move_enemy(game, 0, 1);
	else if (dir == 3)
		ft_move_enemy(game, 1, -1);
	else if (dir == 4)
		ft_move_enemy(game, 1, 1);

}
