/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:16:07 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/15 12:21:12 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

void	ft_img_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->ptr + (y * img->line + x * (img->pixel / 8));
	*(int *)pixel = color;
}

void	ft_img_fill(t_img *img, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			ft_img_pixel(img, i, j, color);
			j++;
		}
		i++;
	}
}

void	ft_print_img_data(t_img *img)
{
	if (!img)
		return ;
	printf("ptr : %p\ndata adr : %p\n", img->ptr, img->data);
	ft_printf("bytes by pixel : %d\nsize line : %d\nendian : %d\n", \
		img->pixel, img->line, img->endian);
}

int	main(void)
{
	t_mlx	mlx;
	t_img	img;

	mlx.screen = mlx_init();
	if (!mlx.screen)
		return (-1);
	mlx.win = mlx_new_window(mlx.screen, 400, 400, "So long my friend..");
	if (!mlx.win)
		return (-1);
	mlx_key_hook(mlx.win, &ft_hook_key, (void *) &mlx);
	mlx_pixel_put(mlx.screen, mlx.win, 400 / 2, 400 / 2, 0xFFFFFF);
	img.ptr = mlx_new_image(mlx.screen, 400, 400);
	img.height = 400;
	if (!img.ptr)
		ft_putendl_fd("Error creating new image", 1);
	img.data = mlx_get_data_addr(img.ptr, &img.pixel, \
		&img.line, &img.endian);
	ft_print_img_data(&img);
	ft_img_pixel(&img, 20, 20, 0xFFFFFF);
	mlx_put_image_to_window(mlx.screen, mlx.win, img.ptr, 0, 0);
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