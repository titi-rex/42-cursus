/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:07:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/15 11:18:03 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_map
{
	char	**layout;
	int		ysize;
	int		xsize;
	int		count[3];
}	t_map;

typedef struct s_img
{
	void	*ptr;
	char	*data;
	int		pixel;
	int		line;
	int		endian;
	int		height;
}	t_img;

typedef struct s_mlx
{
	void	*screen;
	void	*win;
	t_img	img;
}	t_mlx;



void	ft_error(t_map *map, int errnum, char *errstr);
void	ft_print_map(t_map *map);

char	**ft_get_map(char *pathname);
void	ft_get_mapsize(t_map *map);

void	ft_check_map(t_map *map);
void	ft_backtrack(t_map *map, int ypos, int xpos);
void	ft_init_map(t_map *map, char *pathname);

void	ft_free2d(void **arr, int size);



int		ft_hook_key(int keycode, t_mlx *data);

#endif