/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:41:10 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/27 13:51:03 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_animate_idle(t_game_data *game)
{
	static int	i;

	if (i % 10000 == 0)
	{
		ft_display_tile(&game->mlx, &game->idle[i / 10000], \
			game->pos[1], game->pos[0]);
		if (i <= 30000 && game->badguys)
			ft_display_tile(&game->mlx, &game->enemy[i / 10000], \
				game->pos_b[1], game->pos_b[0]);
	}
	i++;
	if (i >= 60000)
		i = 0;
}

void	ft_animate_dead(t_game_data *game)
{
	int	i;

	i = 0;
	while (i <= 100000)
	{
		ft_display_tile(&game->mlx, &game->dead[i / 20000], game->pos[1], \
			game->pos[0]);
		i++;
	}
}

void	ft_animate_run(t_game_data *game, t_sprite *sprite, int dir)
{
	int	i;
	int	offset;

	i = 0;
	offset = 0;
	while (i < 14000)
	{
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, sprite \
			[i / 2000].id, (game->pos[1] + dir) * TILE + offset, game->pos[0] * \
				TILE);
		if (i % 2000 == 0)
		{
			if (game->map.layout[game->pos[0]][game->pos[1] + dir] == 'E')
				ft_display_tile(&game->mlx, &game->exit, game->pos[1] + dir, \
					game->pos[0]);
			else
				ft_display_tile(&game->mlx, &game->floor, game->pos[1] + dir, \
					game->pos[0]);
			offset = offset + (-dir * 12);
		}
		i++;
	}
}

void	ft_animate_jump(t_game_data *game, t_sprite *sprite, int dir)
{
	int	i;
	int	offset;

	i = 0;
	offset = 8;
	while (i < 12000)
	{
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, sprite \
			[i / 1000].id, (game->pos[1] * TILE) + 15, (game->pos[0] + dir) * \
				TILE + offset);
		if (i % 1000 == 0)
		{
			if (game->map.layout[game->pos[0] + dir][game->pos[1]] == 'E')
				ft_display_tile(&game->mlx, &game->exit, game->pos[1], \
					game->pos[0] + dir);
			else
				ft_display_tile(&game->mlx, &game->floor, game->pos[1], \
					game->pos[0] + dir);
			offset = offset + (-dir * 8);
		}
		i++;
	}
}

int	ft_init_sprite_misc(t_game_data *game)
{
	int	tmp;

	game->wall[0].id = mlx_xpm_file_to_image(game->mlx.ptr, WALL1, &tmp, &tmp);
	game->wall[1].id = mlx_xpm_file_to_image(game->mlx.ptr, WALL2, &tmp, &tmp);
	game->floor.id = mlx_xpm_file_to_image(game->mlx.ptr, FLOOR, &tmp, &tmp);
	game->exit.id = mlx_xpm_file_to_image(game->mlx.ptr, EXIT_C, &tmp, &tmp);
	if (!game->floor.id || !game->wall[0].id || !game->exit.id || \
			!game->wall[1].id)
		return (1);
	return (0);
}
