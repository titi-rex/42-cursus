/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:39:15 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/17 17:30:37 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_destroy_sprite(t_game_data *game)
{
	if (game->floor.id)
		mlx_destroy_image(game->mlx.ptr, game->floor.id);
	if (game->player.id)
		mlx_destroy_image(game->mlx.ptr, game->player.id);
	if (game->gem.id)
		mlx_destroy_image(game->mlx.ptr, game->gem.id);
	if (game->wall.id)
		mlx_destroy_image(game->mlx.ptr, game->wall.id);
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

void	ft_quit(t_game_data *game, char *strerr, int exit_code)
{
	if (strerr)
		ft_putendl_fd(strerr, 2);
	ft_clean_exit(game, exit_code);
}
