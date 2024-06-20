/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:16:07 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/20 11:10:13 by tlegrand         ###   ########.fr       */
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
	ft_init_mlx(&game);
	ft_init_sprite(&game);
	ft_init_pos(&game);
	mlx_hook(game.mlx.win, KeyPress, KeyPressMask, ft_hook_key, &game);
	mlx_hook(game.mlx.win, DestroyNotify, StructureNotifyMask, ft_stop, &game);
	ft_display_start(&game);
	mlx_loop(game.mlx.ptr);
	ft_clean_exit(&game, EXIT_FAILURE);
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

void	ft_credit(void)
{
	ft_putendl_fd("\n# ===== Sprites credits ===== #", 1);
	ft_putendl_fd("Found on itch.io :", 1);
	ft_putendl_fd("FreePixelFood by Henry Software", 1);
	ft_putendl_fd("Sprout Lands Asset Pack by Cup NooBle", 1);
	ft_putendl_fd("Cute Legends Heroes Meow-Knight by 9E0", 1);
	ft_putendl_fd("Found on opengameart.org", 1);
	ft_putendl_fd("Cardboard Box by cinamerg", 1);
}
