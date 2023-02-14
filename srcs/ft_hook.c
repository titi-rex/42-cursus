/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:21:53 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/15 00:20:05 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_quit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->screen, mlx->img.ptr);
	mlx_destroy_window(mlx->screen, mlx->win);
	ft_putstr_fd("Quit programe\n", 2);
	exit(0);
}

int	ft_hook_key(int keycode, t_mlx *data)
{
	if (keycode == 65307)
		ft_quit(data);
	ft_printf("key is %d\n", keycode);
	return (0);
}

