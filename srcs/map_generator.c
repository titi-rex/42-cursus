/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:19:31 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/18 17:51:39 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map_gen.h"

void	ft_random_write(int fd)
{
	unsigned char	buff;
	char			*token;
	int				fdrand;
	static int		exit;
	static int		player;

	token = DISTRIBUTION;
	fdrand = open("/dev/urandom", O_RDONLY);
	if (fdrand == -1)
		ft_putstr_exit("Error\nCan't get random", EXIT_FAILURE);
	read(fdrand, &buff, 1);
	write(fd, &token[buff % (sizeof(DISTRIBUTION) - 1 - player) + exit], 1);
	if (token[buff % (sizeof(DISTRIBUTION) - 1 - player) + exit] == 'E')
	{
		exit = 1;
		player = 1;
	}
	if (token[buff % (sizeof(DISTRIBUTION) - 1 - player) + exit] == 'P')
		player = 2;
}

void	ft_generate(int fd, int ysize, int xsize)
{
	int	y;
	int	x;

	y = 0;
	while (y < ysize)
	{
		x = 0;
		while (x < xsize)
		{
			if (y == 0 || x == 0 || y == ysize - 1 || x == xsize - 1)
				write(fd, "1", 1);
			else
				ft_random_write(fd);
			x++;
		}
		write(fd, "\n", 1);
		y++;
	}
}

void	ft_create_map(char *pathname, int ysize, int xsize)
{
	int		fd;
	char	*buff;

	if (xsize == 0)
		xsize = ysize;
	if (ft_is_name_ber(pathname))
	{
		buff = ft_strjoin(pathname, ".ber");
		if (!buff)
			ft_putstr_exit("Error\nMalloc fail", EXIT_FAILURE);
		fd = open(buff, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		free(buff);
	}
	else
		fd = open(pathname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		ft_putstr_exit("Error\nCan't open file", EXIT_FAILURE);
	ft_generate(fd, ysize, xsize);
}

int	main(int argc, char **argv)
{
	if (argc != 3 && argc != 4)
		return (ft_man());
	ft_check_arg(argc, argv);
	if (argc == 3)
		ft_create_map(argv[1], ft_atoi(argv[2]), 0);
	else
		ft_create_map(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	return (0);
}

/*
find better distribution
put everything in a git 
find a way to have only legit map
*/