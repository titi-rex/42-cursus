/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:25:43 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/21 17:41:04 by tlegrand         ###   ########.fr       */
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
/*
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
*/