/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:33:16 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/17 17:33:48 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_move_authorize(char **layout, int pos[2], int axis, int dir)
{
	int	tmp[2];

	tmp[0] = pos[0];
	tmp[1] = pos[1];
	tmp[axis] += dir;
	if (layout[tmp[0]][tmp[1]] == '1')
		return (1);
	return (0);
}

void	ft_map_update(t_game_data *game, int pos[2])
{
	if (game->map.layout[pos[0]][pos[1]] == 'C')
	{
		game->map.count[1]--;
		game->map.layout[pos[0]][pos[1]] = '0';
	}
	if (game->map.count[1] == 0)
		ft_display_exit_open(game);
	if (game->map.count[1] == 0 && game->map.layout[pos[0]][pos[1]] == 'E')
		ft_quit(game, "U win the game!", EXIT_SUCCESS);
}

void	ft_move(t_game_data *game, int axis, int dir)
{
	if (ft_move_authorize(game->map.layout, game->pos, axis, dir))
		return ;
	if (game->map.layout[game->pos[0]][game->pos[1]] == 'E')
		ft_display_tile(&game->mlx, &game->exit, game->pos[1], game->pos[0]);
	else
		ft_display_tile(&game->mlx, &game->floor, game->pos[1], game->pos[0]);
	game->pos[axis] += dir;
	ft_display_tile(&game->mlx, &game->player, game->pos[1], game->pos[0]);
	ft_map_update(game, game->pos);
	game->move++;
	ft_printf("Move : %d\n", game->move);
}
