/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:28:18 by louisa            #+#    #+#             */
/*   Updated: 2023/09/19 20:20:23 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static int	ft_mlx_error(int errnum)
{
	if (errnum == 0)
		return (EXIT_SUCCESS);
	if (errnum == 1)
		ft_putstr_fd("Error\nMlx init fail\n", 2);
	else if (errnum == 2)
		ft_putstr_fd("Error\nNew window fail\n", 2);
	else if (errnum == 3)
		ft_putstr_fd("Error\nNew image fail\n", 2);
	else if (errnum == 4)
		ft_putstr_fd("Error\nGet data from image fail\n", 2);
	return (EXIT_FAILURE);
}

int	ft_init_mlx(t_game *game)
{
	game->mlx.ptr = mlx_init();
	if (!game->mlx.ptr)
		return (ft_mlx_error(1));
	game->mlx.win_width = WIDTH;
	game->mlx.win_height = HEIGHT;
	game->mlx.win = mlx_new_window(game->mlx.ptr, \
		game->mlx.win_width, game->mlx.win_height, "cub3D");
	if (!game->mlx.win)
		return (ft_mlx_error(2));
	game->view.id = mlx_new_image(game->mlx.ptr, \
		game->mlx.win_width, game->mlx.win_height);
	if (!game->view.id)
		return (ft_mlx_error(3));
	game->view.addr = mlx_get_data_addr(game->view.id, \
		&game->view.bpp, &game->view.ll, &game->view.endian);
	if (!game->view.addr)
		return (ft_mlx_error(4));
	game->view.height = game->mlx.win_height;
	game->view.width = game->mlx.win_width;
	return (0);
}

int	load_img(t_mlx *mlx, t_img *img, char *path)
{
	img->id = mlx_xpm_file_to_image(mlx->ptr, path, &img->width, &img->height);
	if (img->id == NULL)
		return (ft_putstr_fd("Error\nCan't load texture\n", 2), 1);
	img->addr = mlx_get_data_addr(img->id, &img->bpp, &img->ll, &img->endian);
	if (img->addr == NULL)
		return (ft_putstr_fd("Error\nCan't get texture data\n", 2), 1);
	return (0);
}
