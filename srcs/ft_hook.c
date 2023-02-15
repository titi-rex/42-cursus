/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:21:53 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/15 18:51:09 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_quit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	ft_putstr_fd("Quit programe\n", 2);
	exit(0);
}

void	ft_colorpath(t_mlx *mlx, int dir)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (dir == 0)
		y = 50;
	else if (dir == 1)
		x = WINDOW_WIDTH - 50;
	else if (dir == 3)
		y = WINDOW_HEIGHT -50;
	else if (dir == 4)
		x = 500;
	mlx->img.id = mlx_new_image(mlx->ptr, 50, 50);
	if (!mlx->img.id)
		ft_putendl_fd("Error creating new image", 1);
	else
	{
		mlx->img.addr = mlx_get_data_addr(mlx->img.id, &mlx->img.bbp, &mlx->img.line, &mlx->img.endian);
		ft_img_fill(&mlx->img, 0x00FFFF);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.id, x, y);
		mlx_destroy_image(mlx->ptr, mlx->img.id);
	}
}

int	ft_hook_key(int keycode, t_mlx *data)
{
	if (keycode == 65307)
		ft_quit(data);
	if (keycode == 65362)
		ft_colorpath(data, 0);
	if (keycode == 65361)
		ft_colorpath(data, 1);
	if (keycode == 65364)
		ft_colorpath(data, 3);
	if (keycode == 65363)
		ft_colorpath(data, 4);
	ft_printf("key is %d\n", keycode);
	return (0);
}

