/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:07:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/17 18:59:52 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
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
	int			pos_e[2];
	int			move;
	t_map		map;
	t_mlx		mlx;
	t_sprite	floor;
	t_sprite	player[6];
	t_sprite	gem;
	t_sprite	wall;
	t_sprite	exit;
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


int		ft_hook_key(int keycode, t_game_data *game);
int		ft_stop(t_game_data *game);

# define UP	65362
# define DOWN	65364
# define LEFT	65361
# define RIGHT	65363
# define ESC	65307


void	ft_display_tile(t_mlx *mlx, t_sprite *tile, int x, int y);
void	ft_display_start(t_game_data *game);
void	ft_display_exit_open(t_game_data *game);
void	ft_move(t_game_data *game, int axis, int dir);

int		ft_animate_player(t_game_data *game);

# ifndef TILE
#  define TILE 90
# endif

# define CHARA1	"sprites/idle_1.xpm"
# define CHARA2	"sprites/idle_2.xpm"
# define CHARA3	"sprites/idle_3.xpm"
# define CHARA4	"sprites/idle_4.xpm"
# define CHARA5	"sprites/idle_5.xpm"
# define CHARA6	"sprites/idle_6.xpm"


# define FLOOR	"sprites/grass_1.xpm"
# define GEM	"sprites/run_5.xpm"
# define WALL	"sprites/tree_1.xpm"
# define EXIT_C	"sprites/bush.xpm"
# define EXIT_O	"sprites/run_8.xpm"

void	ft_free2d(void **arr, int size);
void	ft_clean_exit(t_game_data *game, int exit_code);
void	ft_quit(t_game_data *game, char *strerr, int exit_code);

#endif