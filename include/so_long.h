/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:07:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/17 11:30:08 by tlegrand         ###   ########.fr       */
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
# include "img_draw.h"

typedef struct s_map
{
	char	**layout;
	int		ysize;
	int		xsize;
	int		count[3];
}	t_map;

typedef struct s_sprite
{
	void	*id;
	int		height;
	int		width;
}	t_sprite;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_game
{
	int			pos[2];
	t_map		map;
	t_mlx		mlx;
	t_sprite	floor;
	t_sprite	player;
	t_sprite	gem;
	t_sprite	wall;
	t_sprite	exit[2];
}	t_game_data;


# ifndef W_HEIGHT
#  define W_HEIGHT 500
# endif
# ifndef W_WIDTH
#  define W_WIDTH 500
# endif

void	ft_error_map(t_map *map, int errnum, char *errstr);
void	ft_print_map(t_map *map);
char	**ft_get_map(char *pathname);
void	ft_get_mapsize(t_map *map);
void	ft_check_map(t_map *map);
void	ft_backtrack(t_map *map, int ypos, int xpos);
void	ft_init_map(t_map *map, char *pathname);
void	ft_clean_map(t_map *map);

void	ft_init_game(t_game_data *game);
void	ft_init_mlx(t_game_data *game);
void	ft_init_sprite(t_game_data *game);
void	ft_init_pos(t_game_data *game);

int		ft_hook_key(int keycode, t_mlx *data);


void	ft_img_fill(t_img *img, int color);

# define FLOOR	"sprites/background.xpm"
# define CHARA	"sprites/character.xpm"
# define GEM	"sprites/gems.xpm"
# define WALL	"sprites/wall.xpm"
# define EXIT_C	"sprites/exit_close.xpm"
# define EXIT_O	"sprites/exit_open.xpm"

void	ft_free2d(void **arr, int size);
void	ft_clean_exit(t_game_data *game, int exit_code);

#endif