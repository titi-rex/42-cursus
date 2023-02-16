/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:03:45 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/16 18:42:29 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	ft_init_pos(t_game_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.ysize)
	{
		j = 0;
		while (j < game->map.xsize)
		{
			if (game->map.layout[i][j] == 'P')
			{
				game->pos[0] = i;
				game->pos[1] = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_init_mlx_(t_game_data *game)
{
	game->mlx.ptr = mlx_init();
	if (!game->mlx.ptr)
		return ;
	game->mlx.win = mlx_new_window(game->mlx.ptr, W_WIDTH, W_HEIGHT, "So long");
	if (!game->mlx.win)
		return ;
}

void	ft_init_sprite(t_game_data *game)
{
	game->backround.id = mlx_xpm_file_to_image(game->mlx.ptr, BGRD, NULL, NULL);
	game->player.id = mlx_xpm_file_to_image(game->mlx.ptr, CHARA, NULL, NULL);
	game->gem.id = mlx_xpm_file_to_image(game->mlx.ptr, GEM, NULL, NULL);
	game->wall.id = mlx_xpm_file_to_image(game->mlx.ptr, WALL, NULL, NULL);
	game->exit[0].id = mlx_xpm_file_to_image(game->mlx.ptr, EXIT_C, NULL, NULL);
	game->exit[1].id = mlx_xpm_file_to_image(game->mlx.ptr, EXIT_O, NULL, NULL);
}

void	ft_clean_exit(t_game_data *game, int exit_code)
{
	ft_clean_map(game->map);
	ft_destroy_sprite(game);
	ft_destroy_mlx(game);
	exit(exit_code);
}
