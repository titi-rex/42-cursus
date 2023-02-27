/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:03:45 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/27 15:01:04 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_init_sprite_loop(t_sprite *sprite, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		sprite[i].id = NULL;
		i++;
	}
}

void	ft_init_game(t_game_data *game)
{
	game->pos[0] = 1;
	game->pos[1] = 1;
	game->pos_e[0] = 0;
	game->pos_e[1] = 0;
	game->pos_b[0] = 0;
	game->pos_b[1] = 0;
	game->move = 0;
	game->badguys = 0;
	game->pause = 0;
	game->mlx.ptr = NULL;
	game->mlx.win = NULL;
	game->floor.id = NULL;
	game->wall[0].id = NULL;
	game->wall[1].id = NULL;
	game->exit.id = NULL;
	ft_init_sprite_loop(game->idle, 6);
	ft_init_sprite_loop(game->dead, 6);
	ft_init_sprite_loop(game->run_r, 8);
	ft_init_sprite_loop(game->run_l, 8);
	ft_init_sprite_loop(game->jump, 12);
	ft_init_sprite_loop(game->enemy, 4);
	ft_init_sprite_loop(game->gui, 3);
	ft_init_sprite_loop(game->gem, 5);
	ft_init_sprite_loop(game->sign, 11);
}

void	ft_init_pos(t_game_data *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->map.ysize - 1)
	{
		j = 1;
		while (j < game->map.xsize - 1)
		{
			if (game->map.layout[i][j] == 'P')
			{
				game->pos[0] = i;
				game->pos[1] = j;
			}
			if (game->map.layout[i][j] == 'E')
			{
				game->pos_e[0] = i;
				game->pos_e[1] = j;
			}
			if (game->pos[0] && game->pos_e[0])
				return ;
			j++;
		}
		i++;
	}
}

void	ft_init_mlx(t_game_data *game)
{
	int	w_widht;
	int	w_height;

	w_widht = game->map.xsize * TILE;
	w_height = game->map.ysize * TILE;
	game->mlx.ptr = mlx_init();
	if (!game->mlx.ptr)
		return (ft_putstr_quit(game, "Error\nMlx init fail", EXIT_FAILURE));
	game->mlx.win = mlx_new_window(game->mlx.ptr, w_widht, w_height, "So long");
	if (!game->mlx.win)
		return (ft_putstr_quit(game, "Error\nNew window fail", EXIT_FAILURE));
}
