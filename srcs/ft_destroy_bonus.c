/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:04:48 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/18 15:14:15 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_destroy_sprite(t_game_data *game)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (game->player[i].id)
			mlx_destroy_image(game->mlx.ptr, game->player[i].id);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (game->gem[i].id)
			mlx_destroy_image(game->mlx.ptr, game->gem[i].id);
		i++;
	}
	if (game->floor.id)
		mlx_destroy_image(game->mlx.ptr, game->floor.id);
	if (game->wall[0].id)
		mlx_destroy_image(game->mlx.ptr, game->wall[0].id);
	if (game->wall[1].id)
		mlx_destroy_image(game->mlx.ptr, game->wall[1].id);
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
