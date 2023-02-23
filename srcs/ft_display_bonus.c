/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:55:37 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/23 13:14:55 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_display_tile(t_mlx *mlx, t_sprite *tile, int x, int y)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, tile->id, x * TILE, y * TILE);
}

void	ft_choose_tile(t_game_data *game, int x, int y)
{
	if (game->map.layout[y][x] == '0')
		ft_display_tile(&game->mlx, &game->floor, x, y);
	else if (game->map.layout[y][x] == 'P')
		ft_display_tile(&game->mlx, &game->idle[0], x, y);
	else if (game->map.layout[y][x] == 'C')
		ft_display_tile(&game->mlx, &game->gem[x % 3 + y % 3], x, y);
	else if (game->map.layout[y][x] == '1')
		ft_display_tile(&game->mlx, &game->wall[(x + (y >> 1)) % 2], x, y);
	else if (game->map.layout[y][x] == 'E')
		ft_display_tile(&game->mlx, &game->exit, x, y);
}

void	ft_display_all(t_game_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.ysize)
	{
		j = 0;
		while (j < game->map.xsize)
		{
			ft_choose_tile(game, j, i);
			j++;
		}
		i++;
	}
	ft_display_move(game);
	if (game->badguys)
		ft_display_tile(&game->mlx, &game->enemy[0], game->pos_b[1], \
			game->pos_b[0]);
}

void	ft_display_exit_open(t_game_data *game)
{
	int	tmp;

	mlx_destroy_image(game->mlx.ptr, game->exit.id);
	game->exit.id = mlx_xpm_file_to_image(game->mlx.ptr, EXIT_O, &tmp, &tmp);
	ft_display_tile(&game->mlx, &game->exit, game->pos_e[1], game->pos_e[0]);
}

void	ft_display_move(t_game_data *game)
{
	int	m;

	if (game->pause)
		return ;
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->sign[10].id, \
		0, 0);
	m = game->move % 1000;
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->sign[m / 100]. \
		id, 118, 36);
	m %= 100;
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->sign[m / 10]. \
		id, 127, 36);
	m %= 10;
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->sign[m].id, \
		136, 36);
}
