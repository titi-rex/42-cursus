/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites_bonus_master.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:59:26 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/21 19:17:18 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_init_sprite_jump_u(t_mlx *mlx, t_sprite jump_u[12])
{
	int	tmp;

	jump_u[0].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_U0, &tmp, &tmp);
	jump_u[1].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_U1, &tmp, &tmp);
	jump_u[2].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_U2, &tmp, &tmp);
	jump_u[3].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_U3, &tmp, &tmp);
	if (!jump_u[0].id || !jump_u[1].id || !jump_u[2].id || !jump_u[3].id)
		return (1);
	jump_u[4].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_U4, &tmp, &tmp);
	jump_u[5].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_U5, &tmp, &tmp);
	jump_u[6].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_U6, &tmp, &tmp);
	jump_u[7].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_U7, &tmp, &tmp);
	if (!jump_u[4].id || !jump_u[5].id || !jump_u[6].id || !jump_u[7].id)
		return (1);
	jump_u[8].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_U8, &tmp, &tmp);
	jump_u[9].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_U9, &tmp, &tmp);
	jump_u[10].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_U10, &tmp, &tmp);
	jump_u[11].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_U11, &tmp, &tmp);
	if (!jump_u[8].id || !jump_u[9].id || !jump_u[10].id || !jump_u[11].id)
		return (1);
	return (0);
}

int	ft_init_sprite_jump_d(t_mlx *mlx, t_sprite jump_l[12])
{
	int	tmp;

	jump_l[0].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_D0, &tmp, &tmp);
	jump_l[1].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_D1, &tmp, &tmp);
	jump_l[2].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_D2, &tmp, &tmp);
	jump_l[3].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_D3, &tmp, &tmp);
	if (!jump_l[0].id || !jump_l[1].id || !jump_l[2].id || !jump_l[3].id)
		return (1);
	jump_l[4].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_D4, &tmp, &tmp);
	jump_l[5].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_D5, &tmp, &tmp);
	jump_l[6].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_D6, &tmp, &tmp);
	jump_l[7].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_D7, &tmp, &tmp);
	if (!jump_l[4].id || !jump_l[5].id || !jump_l[6].id || !jump_l[7].id)
		return (1);
	jump_l[8].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_D8, &tmp, &tmp);
	jump_l[9].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_D9, &tmp, &tmp);
	jump_l[10].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_D10, &tmp, &tmp);
	jump_l[11].id = mlx_xpm_file_to_image(mlx->ptr, JUMP_D11, &tmp, &tmp);
	if (!jump_l[8].id || !jump_l[9].id || !jump_l[10].id || !jump_l[11].id)
		return (1);
	return (0);
}

int	ft_init_sprite_sign(t_mlx *mlx, t_sprite sign[5])
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
	if (ft_init_sprite_idle_exit(&game->mlx, game->idle_exit))
		ft_putstr_quit(game, "Error\nCan't load idle_e sprites", EXIT_FAILURE);
	if (ft_init_sprite_run_r(&game->mlx, game->run_r))
		ft_putstr_quit(game, "Error\nCan't load run_r sprites", EXIT_FAILURE);
	if (ft_init_sprite_run_l(&game->mlx, game->run_l))
		ft_putstr_quit(game, "Error\nCan't load run_l sprites", EXIT_FAILURE);
	if (ft_init_sprite_gem(&game->mlx, game->gem))
		ft_putstr_quit(game, "Error\nCan't load gem sprites", EXIT_FAILURE);
	if (ft_init_sprite_sign(&game->mlx, game->sign))
		ft_putstr_quit(game, "Error\nCan't load sign sprites", EXIT_FAILURE);
	game->wall[0].id = mlx_xpm_file_to_image(game->mlx.ptr, WALL1, &tmp, &tmp);
	game->wall[1].id = mlx_xpm_file_to_image(game->mlx.ptr, WALL2, &tmp, &tmp);
	game->floor.id = mlx_xpm_file_to_image(game->mlx.ptr, FLOOR, &tmp, &tmp);
	game->exit.id = mlx_xpm_file_to_image(game->mlx.ptr, EXIT_C, &tmp, &tmp);
	if (!game->floor.id || !game->wall[0].id || !game->exit.id || \
			!game->wall[1].id)
		ft_putstr_quit(game, "Error\nCan't load sprites", EXIT_FAILURE);
}
