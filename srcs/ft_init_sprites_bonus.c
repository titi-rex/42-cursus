/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:59:26 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/22 17:50:00 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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

int	ft_init_sprite_enemy(t_mlx *mlx, t_sprite enemy[4])
{
	int	tmp;

	enemy[0].id = mlx_xpm_file_to_image(mlx->ptr, BAD1, &tmp, &tmp);
	enemy[1].id = mlx_xpm_file_to_image(mlx->ptr, BAD2, &tmp, &tmp);
	enemy[2].id = mlx_xpm_file_to_image(mlx->ptr, BAD3, &tmp, &tmp);
	enemy[3].id = mlx_xpm_file_to_image(mlx->ptr, BAD4, &tmp, &tmp);
	if (!enemy[0].id || !enemy[1].id || !enemy[2].id || !enemy[3].id)
		return (1);
	return (0);
}

int	ft_init_sprite_gui(t_mlx *mlx, t_sprite gui[3])
{
	int	tmp;

	gui[0].id = mlx_xpm_file_to_image(mlx->ptr, GUI1, &tmp, &tmp);
	gui[1].id = mlx_xpm_file_to_image(mlx->ptr, GUI2, &tmp, &tmp);
	gui[2].id = mlx_xpm_file_to_image(mlx->ptr, GUI3, &tmp, &tmp);
	if (!gui[0].id || !gui[1].id || !gui[2].id)
		return (1);
	return (0);
}

int	ft_init_sprite_sign(t_mlx *mlx, t_sprite sign[11])
{
	int	tmp;

	sign[0].id = mlx_xpm_file_to_image(mlx->ptr, SIGN0, &tmp, &tmp);
	sign[1].id = mlx_xpm_file_to_image(mlx->ptr, SIGN1, &tmp, &tmp);
	sign[2].id = mlx_xpm_file_to_image(mlx->ptr, SIGN2, &tmp, &tmp);
	sign[3].id = mlx_xpm_file_to_image(mlx->ptr, SIGN3, &tmp, &tmp);
	if (!sign[0].id || !sign[1].id || !sign[2].id || !sign[3].id)
		return (1);
	sign[4].id = mlx_xpm_file_to_image(mlx->ptr, SIGN4, &tmp, &tmp);
	sign[5].id = mlx_xpm_file_to_image(mlx->ptr, SIGN5, &tmp, &tmp);
	sign[6].id = mlx_xpm_file_to_image(mlx->ptr, SIGN6, &tmp, &tmp);
	sign[7].id = mlx_xpm_file_to_image(mlx->ptr, SIGN7, &tmp, &tmp);
	if (!sign[4].id || !sign[5].id || !sign[6].id || !sign[7].id)
		return (1);
	sign[8].id = mlx_xpm_file_to_image(mlx->ptr, SIGN8, &tmp, &tmp);
	sign[9].id = mlx_xpm_file_to_image(mlx->ptr, SIGN9, &tmp, &tmp);
	sign[10].id = mlx_xpm_file_to_image(mlx->ptr, SIGN10, &tmp, &tmp);
	if (!sign[8].id || !sign[9].id || !sign[10].id)
		return (1);
	return (0);
}

void	ft_init_sprite(t_game_data *game)
{
	int	tmp;

	if (ft_init_sprite_idle(&game->mlx, game->idle))
		ft_putstr_quit(game, "Error\nCan't load idle sprites", EXIT_FAILURE);
	// if (ft_init_sprite_dead(&game->mlx, game->dead))
	// 	ft_putstr_quit(game, "Error\nCan't load dead sprites", EXIT_FAILURE);
	if (ft_init_sprite_run_r(&game->mlx, game->run_r))
		ft_putstr_quit(game, "Error\nCan't load run_r sprites", EXIT_FAILURE);
	if (ft_init_sprite_run_l(&game->mlx, game->run_l))
		ft_putstr_quit(game, "Error\nCan't load run_l sprites", EXIT_FAILURE);
	if (ft_init_sprite_jump(&game->mlx, game->jump))
		ft_putstr_quit(game, "Error\nCan't load jump sprites", EXIT_FAILURE);
	if (ft_init_sprite_gem(&game->mlx, game->gem))
		ft_putstr_quit(game, "Error\nCan't load gem sprites", EXIT_FAILURE);
	if (ft_init_sprite_enemy(&game->mlx, game->enemy))
		ft_putstr_quit(game, "Error\nCan't load enemy sprites", EXIT_FAILURE);
	if (ft_init_sprite_sign(&game->mlx, game->sign))
		ft_putstr_quit(game, "Error\nCan't load sign sprites", EXIT_FAILURE);
	if (ft_init_sprite_gui(&game->mlx, game->gui))
		ft_putstr_quit(game, "Error\nCan't load gui sprites", EXIT_FAILURE);
	game->wall[0].id = mlx_xpm_file_to_image(game->mlx.ptr, WALL1, &tmp, &tmp);
	game->wall[1].id = mlx_xpm_file_to_image(game->mlx.ptr, WALL2, &tmp, &tmp);
	game->floor.id = mlx_xpm_file_to_image(game->mlx.ptr, FLOOR, &tmp, &tmp);
	game->exit.id = mlx_xpm_file_to_image(game->mlx.ptr, EXIT_C, &tmp, &tmp);
	if (!game->floor.id || !game->wall[0].id || !game->exit.id || \
			!game->wall[1].id)
		ft_putstr_quit(game, "Error\nCan't load sprites", EXIT_FAILURE);
}
