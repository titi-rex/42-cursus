/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:41:10 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/20 16:26:53 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_animate_idle(t_game_data *game)
{
	static int	i;

	if (game->map.layout[game->pos[0]][game->pos[1]] != 'E')
	{
		if (i % 10000 == 0)
			ft_display_tile(&game->mlx, &game->idle[i / 10000], game->pos[1], game->pos[0]);
		i++;
		if (i >= 60000)
			i = 0;
	}
}

void	ft_animate_run_r(t_game_data *game)
{
	int	i;
	int	offset;

	i = 0;
	offset = 0;
	while (i < 14000)
	{
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->run_r \
			[i / 2000].id, (game->pos[1] - 1) * TILE + offset, game->pos[0] * TILE);
		if (i % 2000 == 0)
		{
			if (game->map.layout[game->pos[0]][game->pos[1] - 1] == 'E')
				ft_display_tile(&game->mlx, &game->exit, game->pos[1] - 1, game->pos[0]);
			else
			ft_display_tile(&game->mlx, &game->floor, game->pos[1] - 1, game->pos[0]);
			offset += 12;
		}
		i++;
	}

}
