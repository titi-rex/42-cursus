/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:25:43 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/22 00:42:26 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_randuint(int min, int max, int *err)
{
	unsigned int	c;
	int				fd;

	c = 0;
	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		*err = 0;
	else
	{
		if (read(fd, &c, 1) == -1)
			*err = 0;
		close (fd);
	}
	return (c % (max - min) + min);
}

void	ft_init_enemy_secure(t_game_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.ysize)
	{
		j = 0;
		while (j < game->map.xsize)
		{
			if (game->map.layout[i][j] == '0')
			{
				game->pos_b[0] = i;
				game->pos_b[1] = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_init_enemy(t_game_data *game)
{
	int	i;
	int	j;
	int	wit;

	if (!game->badguys)
		return ;
	i = 0;
	j = 0;
	wit = 50;
	while (game->map.layout[i][j] != '0')
	{
		i = ft_randuint(1, game->map.ysize, &wit);
		j = ft_randuint(1, game->map.xsize, &wit);
		wit--;
		if (wit <= 0)
			return ((void) ft_init_enemy_secure(game));
	}
	game->pos_b[0] = i;
	game->pos_b[1] = j;
}

void	ft_move_enemy(t_game_data *game, int axis, int dir)
{
	if (ft_move_authorize(game->map.layout, game->pos_b, axis, dir))
		return ;
	if (game->map.layout[game->pos_b[0]][game->pos_b[1]] == 'E')
		ft_display_tile(&game->mlx, &game->exit, game->pos_b[1], \
			game->pos_b[0]);
	else if (game->map.layout[game->pos_b[0]][game->pos_b[1]] == 'C')
		ft_display_tile(&game->mlx, &game->gem[game->pos_b[1] % 3 + game->pos_b \
			[0] % 3], game->pos_b[1], game->pos_b[0]);
	else
		ft_display_tile(&game->mlx, &game->floor, game->pos_b[1], \
			game->pos_b[0]);
	game->pos_b[axis] += dir;
	ft_display_tile(&game->mlx, &game->enemy[1], game->pos_b[1], \
		game->pos_b[0]);
	ft_is_lost(game);
}

void	ft_select_move_enemy(t_game_data *game)
{
	int	dir;
	int	err;

	err = 1;
	dir = ft_randuint(1, 4, &err);
	if (err == 0)
		return ((void) ft_putendl_fd("Randuint for enemy move fail", 2));
	else if (dir == 1)
		ft_move_enemy(game, 0, -1);
	else if (dir == 2)
		ft_move_enemy(game, 0, 1);
	else if (dir == 3)
		ft_move_enemy(game, 1, -1);
	else if (dir == 4)
		ft_move_enemy(game, 1, 1);

}
