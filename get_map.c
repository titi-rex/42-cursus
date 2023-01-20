/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:50:46 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/20 16:46:26 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_file_size(char *pathname)
{
	int		fd;
	int		size;
	char	buff;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		ft_error(NULL, 3, "File : Failed to open\n");
	size = 1;
	while (read(fd, &buff, 1))
			size++;
	close(fd);
	return (size);
}

char	**ft_get_map(char *pathname)
{
	char	**map;
	char	*line;
	int		fd;
	int		size;

	size = ft_file_size(pathname);
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		ft_error(NULL, 3, "File : Failed to open\n");
	line = (char *)ft_calloc(size, sizeof(char));
	if (!line)
		ft_error(NULL, 12, NULL);
	if (read (fd, line, size) == -1)
		ft_error(NULL, 5, "File : Failed to read\n");
	map = ft_split(line, '\n');
	free(line);
	if (!map)
		ft_error(NULL, 12, NULL);
	close(fd);
	return (map);
}

int	ft_get_ysize(char **layout)
{
	int	i;

	i = 0;
	while (layout[i])
		i++;
	return (i);
}

int	ft_get_xsize(char **layout)
{
	size_t	len;
	int		i;

	i = 1;
	len = ft_strlen(layout[0]);
	while (layout[i])
	{
		if (len != ft_strlen(layout[i]))
			return (-1);
		i++;
	}
	return ((int) len);
}

void	ft_get_mapsize(t_map *map)
{
	map->ysize = ft_get_ysize(map->layout);
	map->xsize = ft_get_xsize(map->layout);
	if (map->ysize == 0 || map->xsize == -1)
		ft_error(map, 3, "Map : Not a rectangle\n");
}
