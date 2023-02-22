/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:42:19 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/22 17:56:21 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/img_draw.h"

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
	ft_printf("ptr : %p\ndata adr : %p\n", img->id, img->addr);
	ft_printf("bites by pixel : %d\nsize line : %d\nendian : %d\n", \
		img->bbp, img->line, img->endian);
	ft_printf("height : %d\nwidth : %d\n", img->height, img->width);
}
