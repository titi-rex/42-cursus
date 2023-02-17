/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:16:07 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/17 18:17:34 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_man(int num);

int	main(int argc, char **argv)
{
	t_game_data	game;

	if (argc != 2)
		return (ft_man(argc));
	ft_init_game(&game);
	ft_init_map(&game.map, argv[1]);
	ft_printf("xsize : %d\tysize : %d\n", game.map.xsize, game.map.ysize);
	ft_init_mlx(&game);
	ft_init_sprite(&game);
	ft_init_pos(&game);
	ft_printf("start: ypos : %d\txpos : %d\n", game.pos[0], game.pos[1]);
	mlx_hook(game.mlx.win, KeyPress, KeyPressMask, ft_hook_key, &game);
	mlx_hook(game.mlx.win, DestroyNotify, StructureNotifyMask, ft_stop, &game);
	ft_display_start(&game);
	mlx_loop(game.mlx.ptr);
	ft_clean_exit(&game, EXIT_SUCCESS);
	return (0);
}

int	ft_man(int num)
{
	if (num == 1)
		ft_printf("So long need a map!\n");
	else if (num > 2)
		ft_printf("So long take only 1 parameter!\n");
	ft_printf("Example : ./so_long map.ber\n");
	return (0);
}
