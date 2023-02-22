/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:04:48 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/22 17:50:17 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_destroy_sprite_loop(t_game_data *game, t_sprite *sprite, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sprite[i].id)
			mlx_destroy_image(game->mlx.ptr, sprite[i].id);
		i++;
	}
}

void	ft_destroy_sprite(t_game_data *game)
{
	ft_destroy_sprite_loop(game, game->idle, 6);
	ft_destroy_sprite_loop(game, game->dead, 6);
	ft_destroy_sprite_loop(game, game->run_r, 8);
	ft_destroy_sprite_loop(game, game->run_l, 8);
	ft_destroy_sprite_loop(game, game->jump, 12);
	ft_destroy_sprite_loop(game, game->gem, 5);
	ft_destroy_sprite_loop(game, game->enemy, 4);
	ft_destroy_sprite_loop(game, game->sign, 11);
	ft_destroy_sprite_loop(game, game->gui, 3);
	ft_destroy_sprite_loop(game, game->wall, 2);
	if (game->floor.id)
		mlx_destroy_image(game->mlx.ptr, game->floor.id);
	if (game->exit.id)
		mlx_destroy_image(game->mlx.ptr, game->exit.id);
}

void	ft_destroy_mlx(t_game_data *game)
{
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.ptr, game->mlx.win);
	if (game->mlx.ptr)
	{
		mlx_destroy_display(game->mlx.ptr);
		free(game->mlx.ptr);
	}
}

void	ft_clean_exit(t_game_data *game, int exit_code)
{
	ft_clean_map(&game->map);
	ft_destroy_sprite(game);
	ft_destroy_mlx(game);
	exit(exit_code);
}

void	ft_putstr_quit(t_game_data *game, char *strerr, int exit_code)
{
	if (strerr)
		ft_putendl_fd(strerr, 2);
	ft_clean_exit(game, exit_code);
}
