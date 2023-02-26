/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:21:57 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/26 18:00:59 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_hook_key(int keycode, t_game_data *game)
{
	if (keycode == 65307)
	{
		ft_credit();
		ft_putstr_quit(game, NULL, EXIT_SUCCESS);
	}
	if (game->pause)
		return (0);
	if (keycode == 32)
		ft_select_move_enemy(game);
	if (keycode == 65362)
		ft_move(game, 0, -1);
	if (keycode == 65364)
		ft_move(game, 0, 1);
	if (keycode == 65361)
		ft_move(game, 1, -1);
	if (keycode == 65363)
		ft_move(game, 1, 1);
	return (0);
}

int	ft_hook_stop(t_game_data *game)
{
	ft_credit();
	ft_putstr_quit(game, NULL, EXIT_SUCCESS);
	return (0);
}

int	ft_hook_loop(t_game_data *game)
{
	if (!game->pause)
		ft_animate_idle(game);
	return (0);
}
