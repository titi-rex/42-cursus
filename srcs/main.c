/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:16:07 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/17 11:24:20 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

int	ft_man(void);

int	main(int argc, char **argv)
{
	t_game_data	game;

	if (argc != 2)
		return (ft_man());
	ft_init_map(&game.map, argv[1]);
	//ft_init_mlx(&game);
	//ft_init_sprite(&game);
	//ft_init_pos(&game);
	
	ft_clean_exit(&game, EXIT_SUCCESS);
	return (0);
}

int	ft_man(void)
{
	ft_printf("So long take only 1 parameter\n");
	return (0);
}
