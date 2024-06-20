/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:44:04 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/16 22:52:31 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_DRAW_H
# define IMG_DRAW_H
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef struct s_img
{
	void	*id;
	char	*addr;
	int		bbp;
	int		line;
	int		endian;
	int		height;
	int		width;
}	t_img;

void	ft_img_pixel(t_img *img, int x, int y, int color);
void	ft_img_fill(t_img *img, int color);

void	ft_print_img_data(t_img *img);

# define BLACK	0x000000
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define WHITE	0xFFFFFF

#endif