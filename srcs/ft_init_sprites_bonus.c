/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:02:52 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/18 15:14:15 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_init_sprite_player(t_mlx *mlx, t_sprite player[6])
{
	int	tmp;

	player[0].id = mlx_xpm_file_to_image(mlx->ptr, CHARA1, &tmp, &tmp);
	player[1].id = mlx_xpm_file_to_image(mlx->ptr, CHARA2, &tmp, &tmp);
	player[2].id = mlx_xpm_file_to_image(mlx->ptr, CHARA3, &tmp, &tmp);
	if (!player[0].id || !player[1].id || !player[2].id)
		return (1);
	player[3].id = mlx_xpm_file_to_image(mlx->ptr, CHARA4, &tmp, &tmp);
	player[4].id = mlx_xpm_file_to_image(mlx->ptr, CHARA5, &tmp, &tmp);
	player[5].id = mlx_xpm_file_to_image(mlx->ptr, CHARA6, &tmp, &tmp);
	player[6].id = mlx_xpm_file_to_image(mlx->ptr, CHARA7, &tmp, &tmp);
	if (!player[3].id || !player[4].id || !player[5].id || !player[6].id)
		return (1);
	return (0);
}

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
	int	tmp;

	if (ft_init_sprite_player(&game->mlx, game->player))
		ft_putstr_quit(game, "Error\nCan't load player sprites", EXIT_FAILURE);
	if (ft_init_sprite_gem(&game->mlx, game->gem))
		ft_putstr_quit(game, "Error\nCan't load gem sprites", EXIT_FAILURE);
	game->wall[0].id = mlx_xpm_file_to_image(game->mlx.ptr, WALL1, &tmp, &tmp);
	game->wall[1].id = mlx_xpm_file_to_image(game->mlx.ptr, WALL2, &tmp, &tmp);
	game->floor.id = mlx_xpm_file_to_image(game->mlx.ptr, FLOOR, &tmp, &tmp);
	game->exit.id = mlx_xpm_file_to_image(game->mlx.ptr, EXIT_C, &tmp, &tmp);
	if (!game->floor.id || !game->wall[0].id \
		|| !game->exit.id || !game->wall[0].id)
		ft_putstr_quit(game, "Error\nCan't load sprites", EXIT_FAILURE);
}