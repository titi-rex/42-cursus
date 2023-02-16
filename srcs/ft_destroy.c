/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:39:15 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/16 18:39:44 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_destroy_sprite(t_game_data *game)
{
	if (!game->backround.id)
		mlx_destroy_image(game->mlx.ptr, game->backround.id);
	if (!game->player.id)
		mlx_destroy_image(game->mlx.ptr, game->player.id);
	if (!game->gem.id)
		mlx_destroy_image(game->mlx.ptr, game->gem.id);
	if (!game->wall.id)
		mlx_destroy_image(game->mlx.ptr, game->wall.id);
	if (!game->exit[0].id)
		mlx_destroy_image(game->mlx.ptr, game->exit[0].id);
	if (!game->exit[1].id)
		mlx_destroy_image(game->mlx.ptr, game->exit[1].id);
}

void	ft_destroy_mlx(t_game_data *game)
{
	if (!game->mlx.win)
		mlx_destroy_window(game->mlx.ptr, game->mlx.win);
	if (!game->mlx.ptr)
	{
		mlx_destroy_display(game->mlx.ptr);
		free(game->mlx.ptr);
	}
}
