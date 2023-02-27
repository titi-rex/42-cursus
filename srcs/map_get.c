/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:50:46 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/26 18:08:10 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief give number of char in file
 * if can't open file, display error and quit
 * 
 * @param pathname pathname of file
 * @return int number of char in file
 */
int	ft_file_size(char *pathname)
{
	int		fd;
	int		size;
	char	buff;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		ft_error_map(NULL, 3, "File : Failed to open\n");
	size = 1;
	while (read(fd, &buff, 1))
		size++;
	close(fd);
	return (size);
}

/**
 * @brief extract map from file
 * if malloc fail or can't read, display error and quit
 * 
 * @param pathname pathname of file
 * @return char** array containing the file split in line
 */
char	**ft_get_map(char *pathname)
{
	char	**map;
	char	*line;
	int		fd;
	int		size;

	size = ft_file_size(pathname);
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		ft_error_map(NULL, 3, "File : Failed to open\n");
	line = (char *)ft_calloc(size, sizeof(char));
	if (!line)
		ft_error_map(NULL, 12, NULL);
	if (read (fd, line, size) == -1)
	{
		close(fd);
		free(line);
		ft_error_map(NULL, 5, "File : Failed to read\n");
	}
	close(fd);
	map = ft_split(line, '\n');
	free(line);
	if (!map)
		ft_error_map(NULL, 12, NULL);
	return (map);
}

/**
 * @brief get the ysize (column lenght)
 * column lenght is also number of line
 * 
 * @param layout map's layout
 * @return int column lenght
 */
int	ft_get_ysize(char **layout)
{
	int	i;

	i = 0;
	while (layout[i])
		i++;
	return (i);
}

/**
 * @brief get the xsize (line lenght) and check if all line have same lenght
 * line lenght is also number of column
 * 
 * @param layout map's layout
 * @return int error : -1 // line lenght
 */
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

/**
 * @brief get ysize and xsize and stock them in map
 * if map isn't rectangular, display error and quit 
 * 
 * @param map map to check size
 */
void	ft_get_mapsize(t_map *map)
{
	map->ysize = ft_get_ysize(map->layout);
	map->xsize = ft_get_xsize(map->layout);
	if (map->ysize == 0 || map->xsize == -1)
		ft_error_map(map, 3, "Map : Not a rectangle\n");
}
