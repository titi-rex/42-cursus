/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:21:57 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/22 17:39:47 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_hook_key(int keycode, t_game_data *game)
{
	if (keycode == ESC)
	{
		ft_credit();
		ft_putstr_quit(game, NULL, EXIT_SUCCESS);
	}
	if (game->pause)
		return (0);
	if (keycode == UP)
		ft_move(game, 0, -1);
	if (keycode == DOWN)
		ft_move(game, 0, 1);
	if (keycode == LEFT)
		ft_move(game, 1, -1);
	if (keycode == RIGHT)
		ft_move(game, 1, 1);
	return (0);
}

int	ft_stop(t_game_data *game)
{
	ft_credit();
	ft_putstr_quit(game, NULL, EXIT_SUCCESS);
	return (0);
}

int	ft_animate_loop(t_game_data *game)
{
	if (!game->pause)
		ft_animate_idle(game);
	return (0);
}
