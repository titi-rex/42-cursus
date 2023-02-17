/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:03:45 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/17 23:50:58 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_game(t_game_data *game)
{
	int	i;

	i = -1;
	game->pos[0] = 0;
	game->pos[1] = 0;
	game->pos_e[0] = 0;
	game->pos_e[1] = 0;
	game->move = 0;
	game->mlx.ptr = NULL;
	game->mlx.win = NULL;
	game->floor.id = NULL;
	game->gem.id = NULL;
	game->wall.id = NULL;
	game->exit.id = NULL;
	while (++i < 6)
		game->player[i].id = NULL;
}

void	ft_init_pos(t_game_data *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->map.ysize - 1)
	{
		j = 1;
		while (j < game->map.xsize - 1)
		{
			if (game->map.layout[i][j] == 'P')
			{
				game->pos[0] = i;
				game->pos[1] = j;
			}
			if (game->map.layout[i][j] == 'E')
			{
				game->pos_e[0] = i;
				game->pos_e[1] = j;
			}
			if (game->pos[0] && game->pos_e[0])
				return ;
			j++;
		}
		i++;
	}
}

void	ft_init_mlx(t_game_data *game)
{
	int	w_widht;
	int	w_height;

	w_widht = game->map.xsize * TILE;
	w_height = game->map.ysize * TILE;
	game->mlx.ptr = mlx_init();
	if (!game->mlx.ptr)
		return (ft_clean_exit(game, EXIT_FAILURE));
	game->mlx.win = mlx_new_window(game->mlx.ptr, w_widht, w_height, "So long");
	if (!game->mlx.win)
		return (ft_clean_exit(game, EXIT_FAILURE));
}

int	ft_init_sprite_player(t_mlx *mlx, t_sprite player[6])
{
	int	tmp;

	player[0].id = mlx_xpm_file_to_image(mlx->ptr, CHARA1, &tmp, &tmp);
	player[1].id = mlx_xpm_file_to_image(mlx->ptr, CHARA2, &tmp, &tmp);
	player[2].id = mlx_xpm_file_to_image(mlx->ptr, CHARA3, &tmp, &tmp);
	if (!player[0].id || !player[1].id || !player[2].id)
		return (1);
	player[3].id = mlx_xpm_file_to_image(mlx->ptr, CHARA4, &tmp, &tmp);
	player[4].id = mlx_xpm_file_to_image(mlx->ptr, CHARA5, &tmp, &tmp);
	player[5].id = mlx_xpm_file_to_image(mlx->ptr, CHARA6, &tmp, &tmp);
	if (!player[3].id || !player[4].id || !player[5].id)
		return (1);
	return (0);
}

void	ft_init_sprite(t_game_data *game)
{
	int	tmp;

	if (ft_init_sprite_player(&game->mlx, game->player))
		ft_quit(game, "Error\nCan't load sprites", EXIT_FAILURE);
	game->floor.id = mlx_xpm_file_to_image(game->mlx.ptr, FLOOR, &tmp, &tmp);
	game->gem.id = mlx_xpm_file_to_image(game->mlx.ptr, GEM, &tmp, &tmp);
	game->wall.id = mlx_xpm_file_to_image(game->mlx.ptr, WALL, &tmp, &tmp);
	if (!game->floor.id || !game->gem.id || !game->wall.id)
		ft_quit(game, "Error\nCan't load sprites", EXIT_FAILURE);
	game->exit.id = mlx_xpm_file_to_image(game->mlx.ptr, EXIT_C, &tmp, &tmp);
	if (!game->exit.id)
		ft_quit(game, "Error\nCan't load sprites", EXIT_FAILURE);
}
