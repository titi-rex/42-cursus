/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endgame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:01:18 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/27 13:09:47 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_is_lost(t_game_data *game)
{
	t_img	end;

	if (game->pos[0] == game->pos_b[0] && game->pos[1] == game->pos_b[1])
	{
		game->pause = 1;
		end.height = TILE;
		end.width = TILE;
		end.id = mlx_new_image(game->mlx.ptr, end.width, end.height);
		if (end.id)
		{
			end.addr = mlx_get_data_addr(end.id, &end.bbp, &end.line, \
				&end.endian);
			ft_img_fill(&end, 0xC7003F);
			ft_curtains(game, end.id, &game->dead[0]);
			mlx_destroy_image(game->mlx.ptr, end.id);
		}
		ft_animate_dead(game);
		ft_display_tile(&game->mlx, &game->gui[1], game->pos[1], \
			game->pos[0] - 1);
		ft_putstr_fd("\nSad.. U let this poor cat die..", 1);
	}
}

void	ft_is_win(t_game_data *game)
{
	t_img	end;

	if (game->map.count[1] != 0)
		return ;
	if (game->map.layout[game->pos[0]][game->pos[1]] == 'E')
	{
		game->pause = 1;
		end.height = TILE;
		end.width = TILE;
		end.id = mlx_new_image(game->mlx.ptr, end.width, end.height);
		if (end.id)
		{
			end.addr = mlx_get_data_addr(end.id, &end.bbp, &end.line, \
				&end.endian);
			ft_img_fill(&end, 0x69F0C5);
			ft_curtains(game, end.id, &game->gui[2]);
			mlx_destroy_image(game->mlx.ptr, end.id);
		}
		ft_display_tile(&game->mlx, &game->gui[2], game->pos[1], game->pos[0]);
		ft_display_tile(&game->mlx, &game->gui[0], game->map.xsize >> 1, \
			game->map.ysize >> 1);
		ft_putstr_fd("\nCongrats! U win the game!", 1);
	}
}

void	ft_map_update(t_game_data *game, int pos[2])
{
	if (game->map.layout[pos[0]][pos[1]] == 'C')
	{
		game->map.count[1]--;
		game->map.layout[pos[0]][pos[1]] = '0';
	}
	if (game->map.count[1] == 0 && game->map.count[2])
	{
		game->map.count[2] = 0;
		ft_display_exit_open(game);
	}
	ft_is_lost(game);
	ft_is_win(game);
}
