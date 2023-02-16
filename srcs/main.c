/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:16:07 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/16 23:40:01 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

int	main(void)
{
	t_mlx	mlx;
	t_img	img;
	t_img	backround;

	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		return (-1);
	mlx.win = mlx_new_window(mlx.ptr, W_WIDTH, W_HEIGHT, "So long..");
	if (!mlx.win)
		return (-1);
	mlx_key_hook(mlx.win, &ft_hook_key, (void *) &mlx);
	backround.width = W_WIDTH;
	backround.height = W_HEIGHT;
	backround.id = mlx_new_image(mlx.ptr, W_WIDTH, W_HEIGHT);
	img.id = mlx_xpm_file_to_image(mlx.ptr, "sprites/run_3.xpm", &img.width, &img.height);
	if (!img.id || !backround.id)
		ft_putendl_fd("Error creating new image", 1);
	else
	{
		backround.addr = mlx_get_data_addr(backround.id, &backround.bbp, &backround.line, &backround.endian);
		ft_img_fill(&backround, BLACK);
		mlx_put_image_to_window(mlx.ptr, mlx.win, backround.id, 0, 0);
		mlx_put_image_to_window(mlx.ptr, mlx.win, img.id, 0, 0);
		mlx_destroy_image(mlx.ptr, backround.id);
		mlx_destroy_image(mlx.ptr, img.id);
	}
	mlx_loop(mlx.ptr);
	return (0);
}
