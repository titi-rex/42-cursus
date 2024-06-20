/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:07:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/27 13:39:37 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <X11/X.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "img_draw.h"

/*	==========	struct	==========	*/
typedef struct s_map
{
	char	**layout;
	int		ysize;
	int		xsize;
	int		count[3];
}	t_map;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_sprite
{
	void	*id;
}	t_sprite;

typedef struct s_game
{
	t_map		map;
	int			pos[2];
	int			pos_e[2];
	int			pos_b[2];
	int			move;
	int			badguys;
	int			pause;
	t_mlx		mlx;
	t_sprite	floor;
	t_sprite	exit;
	t_sprite	wall[2];
	t_sprite	gem[5];
	t_sprite	gui[3];
	t_sprite	sign[11];
	t_sprite	idle[6];
	t_sprite	dead[6];
	t_sprite	run_r[8];
	t_sprite	run_l[8];
	t_sprite	jump[12];
	t_sprite	enemy[4];
}	t_game_data;

/*	==========	general functions	==========	*/
void	ft_init_game(t_game_data *game);
void	ft_init_pos(t_game_data *game);
void	ft_free2d(void **arr, int size);
void	ft_clean_exit(t_game_data *game, int exit_code);
void	ft_putstr_quit(t_game_data *game, char *strerr, int exit_code);
void	ft_credit(void);
void	ft_is_lost(t_game_data *game);
int		ft_randuint(int min, int max, int *err);

/*	==========	map management	==========	*/
void	ft_error_map(t_map *map, int errnum, char *errstr);
void	ft_print_map(t_map *map);
void	ft_map_check_name(char *pathname);
char	**ft_get_map(char *pathname);
void	ft_get_mapsize(t_map *map);
void	ft_check_map(t_map *map);
void	ft_backtrack(t_map *map, int ypos, int xpos);
void	ft_init_map(t_map *map, char *pathname);
void	ft_clean_map(t_map *map);
void	ft_init_enemy(t_game_data *game);
void	ft_map_update(t_game_data *game, int pos[2]);

/*	==========	mlx management	==========	*/
void	ft_init_mlx(t_game_data *game);
int		ft_hook_key(int keycode, t_game_data *game);
int		ft_hook_loop(t_game_data *game);
int		ft_hook_stop(t_game_data *game);

/*	==========	sprite and image	==========	*/
# ifndef TILE
#  define TILE 96
# endif

int		ft_init_sprite_idle(t_mlx *mlx, t_sprite idle[6]);
int		ft_init_sprite_dead(t_mlx *mlx, t_sprite dead[6]);
int		ft_init_sprite_run_r(t_mlx *mlx, t_sprite run_r[6]);
int		ft_init_sprite_run_l(t_mlx *mlx, t_sprite run_l[6]);
int		ft_init_sprite_jump(t_mlx *mlx, t_sprite jump[12]);
int		ft_init_sprite_misc(t_game_data *game);
void	ft_init_sprite(t_game_data *game);

void	ft_display_tile(t_mlx *mlx, t_sprite *tile, int x, int y);
void	ft_display_all(t_game_data *game);
void	ft_curtains(t_game_data *game, void *id, t_sprite *end);
void	ft_display_exit_open(t_game_data *game);
void	ft_animate_idle(t_game_data *game);
void	ft_animate_dead(t_game_data *game);

void	ft_animate_run(t_game_data *game, t_sprite *sprite, int dir);
void	ft_animate_jump(t_game_data *game, t_sprite *sprite, int dir);
void	ft_move(t_game_data *game, int axis, int dir);
void	ft_select_move_enemy(t_game_data *game);
void	ft_display_move(t_game_data *game);

# define IDLE1	"sprites/idle_1.xpm"
# define IDLE2	"sprites/idle_2.xpm"
# define IDLE3	"sprites/idle_3.xpm"
# define IDLE4	"sprites/idle_4.xpm"
# define IDLE5	"sprites/idle_5.xpm"
# define IDLE6	"sprites/idle_6.xpm"

# define DEAD1	"sprites/dead_circle_1.xpm"
# define DEAD2	"sprites/dead_circle_2.xpm"
# define DEAD3	"sprites/dead_circle_3.xpm"
# define DEAD4	"sprites/dead_circle_4.xpm"
# define DEAD5	"sprites/dead_circle_5.xpm"
# define DEAD6	"sprites/dead_circle_6.xpm"

# define RUN_R1	"sprites/run_r_1.xpm"
# define RUN_R2	"sprites/run_r_2.xpm"
# define RUN_R3	"sprites/run_r_3.xpm"
# define RUN_R4	"sprites/run_r_4.xpm"
# define RUN_R5	"sprites/run_r_5.xpm"
# define RUN_R6	"sprites/run_r_6.xpm"
# define RUN_R7	"sprites/run_r_7.xpm"
# define RUN_R8	"sprites/run_r_8.xpm"

# define RUN_L1	"sprites/run_l_1.xpm"
# define RUN_L2	"sprites/run_l_2.xpm"
# define RUN_L3	"sprites/run_l_3.xpm"
# define RUN_L4	"sprites/run_l_4.xpm"
# define RUN_L5	"sprites/run_l_5.xpm"
# define RUN_L6	"sprites/run_l_6.xpm"
# define RUN_L7	"sprites/run_l_7.xpm"
# define RUN_L8	"sprites/run_l_8.xpm"

# define JUMP1	"sprites/jump_1.xpm"
# define JUMP2	"sprites/jump_2.xpm"
# define JUMP3	"sprites/jump_3.xpm"
# define JUMP4	"sprites/jump_4.xpm"
# define JUMP5	"sprites/jump_5.xpm"
# define JUMP6	"sprites/jump_6.xpm"
# define JUMP7	"sprites/jump_7.xpm"
# define JUMP8	"sprites/jump_8.xpm"
# define JUMP9	"sprites/jump_9.xpm"
# define JUMP10	"sprites/jump_10.xpm"
# define JUMP11	"sprites/jump_11.xpm"
# define JUMP12	"sprites/jump_12.xpm"

# define SIGN0	"sprites/sign_zero.xpm"
# define SIGN1	"sprites/sign_one.xpm"
# define SIGN2	"sprites/sign_two.xpm"
# define SIGN3	"sprites/sign_three.xpm"
# define SIGN4	"sprites/sign_four.xpm"
# define SIGN5	"sprites/sign_five.xpm"
# define SIGN6	"sprites/sign_six.xpm"
# define SIGN7	"sprites/sign_seven.xpm"
# define SIGN8	"sprites/sign_eight.xpm"
# define SIGN9	"sprites/sign_nine.xpm"
# define SIGN10	"sprites/sign.xpm"

# define GEM1	"sprites/gem_1.xpm"
# define GEM2	"sprites/gem_2.xpm"
# define GEM3	"sprites/gem_3.xpm"
# define GEM4	"sprites/gem_4.xpm"
# define GEM5	"sprites/gem_5.xpm"

# define BAD1	"sprites/head_1.xpm"
# define BAD2	"sprites/head_2.xpm"
# define BAD3	"sprites/head_3.xpm"
# define BAD4	"sprites/head_4.xpm"

# define GUI1	"sprites/goodend_msg.xpm"
# define GUI2	"sprites/badend_msg.xpm"
# define GUI3	"sprites/peace.xpm"

# define FLOOR	"sprites/grass_1.xpm"
# define WALL1	"sprites/tree_1.xpm"
# define WALL2	"sprites/tree_2.xpm"
# define EXIT_C	"sprites/box_close.xpm"
# define EXIT_O	"sprites/box_open.xpm"
# define STOP1	"sprites/pause1.xpm"

#endif