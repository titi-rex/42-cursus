/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:07:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/15 18:50:15 by tlegrand         ###   ########.fr       */
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
	void	*id;
	char	*addr;
	int		bbp;
	int		line;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_game
{
	t_map	map;
	t_mlx	mlx;
	t_img	backround;
	t_img	character;
	t_img	collectible;
	t_img	wall;
	t_img	exit;
	int		pos[2];
}	t_game_data;


# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 800
# endif
# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 800
# endif

void	ft_error(t_map *map, int errnum, char *errstr);
void	ft_print_map(t_map *map);

char	**ft_get_map(char *pathname);
void	ft_get_mapsize(t_map *map);

void	ft_check_map(t_map *map);
void	ft_backtrack(t_map *map, int ypos, int xpos);
void	ft_init_map(t_map *map, char *pathname);

void	ft_free2d(void **arr, int size);

void	ft_img_fill(t_img *img, int color);

int		ft_hook_key(int keycode, t_mlx *data);

#endif