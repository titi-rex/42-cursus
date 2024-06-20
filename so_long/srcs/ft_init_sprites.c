/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:15:25 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/20 11:07:44 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_init_sprite_gem(t_mlx *mlx, t_sprite gem[5])
{
	int	tmp;

	gem[0].id = mlx_xpm_file_to_image(mlx->ptr, GEM1, &tmp, &tmp);
	gem[1].id = mlx_xpm_file_to_image(mlx->ptr, GEM2, &tmp, &tmp);
	gem[2].id = mlx_xpm_file_to_image(mlx->ptr, GEM3, &tmp, &tmp);
	if (!gem[0].id || !gem[1].id || !gem[2].id)
		return (1);
	gem[3].id = mlx_xpm_file_to_image(mlx->ptr, GEM4, &tmp, &tmp);
	gem[4].id = mlx_xpm_file_to_image(mlx->ptr, GEM5, &tmp, &tmp);
	if (!gem[3].id || !gem[4].id)
		return (1);
	return (0);
}

void	ft_init_sprite(t_game_data *game)
{
	int	n;

	if (ft_init_sprite_gem(&game->mlx, game->gem))
		ft_putstr_quit(game, "Error\nCan't load gem sprites", EXIT_FAILURE);
	game->player[0].id = mlx_xpm_file_to_image(game->mlx.ptr, CHARAE, &n, &n);
	game->player[1].id = mlx_xpm_file_to_image(game->mlx.ptr, CHARA1, &n, &n);
	if (!game->player[0].id || !game->player[1].id)
		ft_putstr_quit(game, "Error\nCan't load sprites", EXIT_FAILURE);
	game->wall[0].id = mlx_xpm_file_to_image(game->mlx.ptr, WALL1, &n, &n);
	game->wall[1].id = mlx_xpm_file_to_image(game->mlx.ptr, WALL2, &n, &n);
	game->floor.id = mlx_xpm_file_to_image(game->mlx.ptr, FLOOR, &n, &n);
	game->exit.id = mlx_xpm_file_to_image(game->mlx.ptr, EXIT_C, &n, &n);
	if (!game->floor.id || !game->wall[0].id \
		|| !game->exit.id || !game->wall[1].id)
		ft_putstr_quit(game, "Error\nCan't load sprites", EXIT_FAILURE);
}
