/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:02:52 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/20 15:18:29 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_init_sprite_idle(t_mlx *mlx, t_sprite idle[6])
{
	int	tmp;

	idle[0].id = mlx_xpm_file_to_image(mlx->ptr, IDLE1, &tmp, &tmp);
	idle[1].id = mlx_xpm_file_to_image(mlx->ptr, IDLE2, &tmp, &tmp);
	idle[2].id = mlx_xpm_file_to_image(mlx->ptr, IDLE3, &tmp, &tmp);
	if (!idle[0].id || !idle[1].id || !idle[2].id)
		return (1);
	idle[3].id = mlx_xpm_file_to_image(mlx->ptr, IDLE4, &tmp, &tmp);
	idle[4].id = mlx_xpm_file_to_image(mlx->ptr, IDLE5, &tmp, &tmp);
	idle[5].id = mlx_xpm_file_to_image(mlx->ptr, IDLE6, &tmp, &tmp);
	idle[6].id = mlx_xpm_file_to_image(mlx->ptr, IDLE7, &tmp, &tmp);
	if (!idle[3].id || !idle[4].id || !idle[5].id || !idle[6].id)
		return (1);
	return (0);
}

int	ft_init_sprite_run_r(t_mlx *mlx, t_sprite run_r[6])
{
	int	tmp;

	run_r[0].id = mlx_xpm_file_to_image(mlx->ptr, RUN_R1, &tmp, &tmp);
	run_r[1].id = mlx_xpm_file_to_image(mlx->ptr, RUN_R2, &tmp, &tmp);
	run_r[2].id = mlx_xpm_file_to_image(mlx->ptr, RUN_R3, &tmp, &tmp);
	run_r[3].id = mlx_xpm_file_to_image(mlx->ptr, RUN_R4, &tmp, &tmp);
	if (!run_r[0].id || !run_r[1].id || !run_r[2].id || !run_r[3].id)
		return (1);
	run_r[4].id = mlx_xpm_file_to_image(mlx->ptr, RUN_R5, &tmp, &tmp);
	run_r[5].id = mlx_xpm_file_to_image(mlx->ptr, RUN_R6, &tmp, &tmp);
	run_r[6].id = mlx_xpm_file_to_image(mlx->ptr, RUN_R7, &tmp, &tmp);
	run_r[7].id = mlx_xpm_file_to_image(mlx->ptr, RUN_R8, &tmp, &tmp);
	if (!run_r[4].id || !run_r[5].id || !run_r[6].id || !run_r[7].id)
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

	if (ft_init_sprite_idle(&game->mlx, game->idle))
		ft_putstr_quit(game, "Error\nCan't load idle sprites", EXIT_FAILURE);
	if (ft_init_sprite_run_r(&game->mlx, game->run_r))
		ft_putstr_quit(game, "Error\nCan't load run sprites", EXIT_FAILURE);
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
