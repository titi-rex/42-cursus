/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:16:07 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/16 18:03:07 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

int	main(void)
{
	t_mlx	mlx;
	t_img	img;

	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		return (-1);
	mlx.win = mlx_new_window(mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "So long..");
	if (!mlx.win)
		return (-1);
	mlx_key_hook(mlx.win, &ft_hook_key, (void *) &mlx);
	img.width = WINDOW_WIDTH;
	img.height = WINDOW_HEIGHT;
	img.id = mlx_xpm_file_to_image(mlx.ptr, "sprites/meow_idle.xpm", &img.width, &img.height);
	if (!img.id)
		ft_putendl_fd("Error creating new image", 1);
	else
	{
		img.addr = mlx_get_data_addr(img.id, &img.bbp, &img.line, &img.endian);
		mlx_put_image_to_window(mlx.ptr, mlx.win, img.id, 0, 0);
		mlx_destroy_image(mlx.ptr, img.id);
	}
	mlx_loop(mlx.ptr);
	return (0);
}
