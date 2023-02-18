/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:21:53 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/18 15:14:15 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_hook_key(int keycode, t_game_data *game)
{
	if (keycode == ESC)
		ft_putstr_quit(game, NULL, EXIT_SUCCESS);
	if (keycode == UP)
		ft_move(game, 0, -1);
	if (keycode == DOWN)
		ft_move(game, 0, 1);
	if (keycode == RIGHT)
		ft_move(game, 1, 1);
	if (keycode == LEFT)
		ft_move(game, 1, -1);
	return (0);
}

int	ft_stop(t_game_data *game)
{
	ft_putstr_quit(game, NULL, EXIT_SUCCESS);
	return (0);
}
