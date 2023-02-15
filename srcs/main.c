/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:16:07 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/15 18:50:38 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

void	ft_img_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line + x * (img->bbp / 8));
	*(int *)pixel = color;
}

void	ft_img_fill(t_img *img, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
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
	printf("ptr : %p\ndata adr : %p\n", img->id, img->addr);
	ft_printf("bytes by pixel : %d\nsize line : %d\nendian : %d\n", \
		img->bbp, img->line, img->endian);
}

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
	img.id = mlx_new_image(mlx.ptr, img.width, img.height);
	if (!img.id)
		ft_putendl_fd("Error creating new image", 1);
	else
	{
		img.addr = mlx_get_data_addr(img.id, &img.bbp, &img.line, &img.endian);
		ft_img_fill(&img, 0x00F0FF);
		mlx_put_image_to_window(mlx.ptr, mlx.win, img.id, 0, 0);
	}
	mlx_loop(mlx.ptr);

	return (0);
}

/*

	mlx_pixel_put(mlx.ptr, mlx.win, 400 / 2, 400 / 2, 0xFFFFFF);

	//void	*win_ptr;
		t_map	carte;
	t_map	*map;

	map = &carte;
	ft_init_map(map, "map.ber");
	ft_print_map(map);
	ft_free2d((void **) map->layout);

	*/