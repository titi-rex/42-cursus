/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:59:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/17 19:06:03 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_display_tile(t_mlx *mlx, t_sprite *tile, int x, int y)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, tile->id, x * TILE, y * TILE);
}

void	ft_choose_tile(t_game_data *game, int x, int y)
{
	if (game->map.layout[y][x] == '0')
		ft_display_tile(&game->mlx, &game->floor, x, y);
	else if (game->map.layout[y][x] == 'P')
		ft_display_tile(&game->mlx, &game->player[0], x, y);
	else if (game->map.layout[y][x] == 'C')
		ft_display_tile(&game->mlx, &game->gem, x, y);
	else if (game->map.layout[y][x] == '1')
		ft_display_tile(&game->mlx, &game->wall, x, y);
	else if (game->map.layout[y][x] == 'E')
		ft_display_tile(&game->mlx, &game->exit, x, y);
}

void	ft_display_start(t_game_data *game)
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
}

void	ft_display_exit_open(t_game_data *game)
{
	int	tmp;

	mlx_destroy_image(game->mlx.ptr, game->exit.id);
	game->exit.id = mlx_xpm_file_to_image(game->mlx.ptr, EXIT_O, &tmp, &tmp);
	ft_display_tile(&game->mlx, &game->exit, game->pos_e[1], game->pos_e[0]);
}

int	ft_animate_player(t_game_data *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		ft_display_tile(&game->mlx, &game->floor, 7, 2);
	
		ft_display_tile(&game->mlx, &game->player[i], 7, 2);
		sleep(1);
		i++;
	}
	return (0);
}
