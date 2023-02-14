/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:16:07 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/15 00:15:08 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(void)
{
	t_mlx	mlx;

	mlx.screen = mlx_init();
	if (!mlx.screen)
		return (-1);
	mlx.win = mlx_new_window(mlx.screen, 400, 400, "So long my friend..");
	if (!mlx.win)
		return (-1);
	mlx_pixel_put(mlx.screen, mlx.win, 400 / 2, 400 / 2, 0xFFFFFF);
	mlx_key_hook(mlx.win, &ft_hook_key, (void *) &mlx);
	mlx.img.ptr = mlx_new_image(mlx.screen, 50, 50);
	if (!mlx.img.ptr)
		ft_putendl_fd("Error creating new image", 2);
	mlx.img.data = mlx_get_data_addr(mlx.img.ptr, &mlx.img.pixel, \
		&mlx.img.line, &mlx.img.endian);
	mlx_put_image_to_window(mlx.screen, mlx.win, mlx.img.ptr, 100, 100);
	mlx_loop(mlx.screen);

	return (0);
}

/*


	//void	*win_ptr;
		t_map	carte;
	t_map	*map;

	map = &carte;
	ft_init_map(map, "map.ber");
	ft_print_map(map);
	ft_free2d((void **) map->layout);

	*/