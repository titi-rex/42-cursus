/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:03:45 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/20 22:14:33 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_init_game(t_game_data *game)
{
	int	i;

	game->pos[0] = 0;
	game->pos[1] = 0;
	game->pos_e[0] = 0;
	game->pos_e[1] = 0;
	game->move = 0;
	game->badguys = 0;
	game->mlx.ptr = NULL;
	game->mlx.win = NULL;
	game->floor.id = NULL;
	game->wall[0].id = NULL;
	game->wall[1].id = NULL;
	game->exit.id = NULL;
	i = -1;
	while (++i < 7)
		game->idle[i].id = NULL;
	i = -1;
	while (++i < 8)
		game->run_r[i].id = NULL;
	i = -1;
	while (++i < 5)
		game->gem[i].id = NULL;
	i = -1;
	while (++i < 11)
		game->sign[i].id = NULL;
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
		return (ft_clean_exit(game, EXIT_FAILURE));
	game->mlx.win = mlx_new_window(game->mlx.ptr, w_widht, w_height, "So long");
	if (!game->mlx.win)
		return (ft_clean_exit(game, EXIT_FAILURE));
}
