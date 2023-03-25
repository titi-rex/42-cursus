/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:15:23 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/25 13:13:35 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_color_table_3bit(char c)
{
	if (c == 'n')
		return (BLACK);
	if (c == 'r')
		return (RED);
	if (c == 'v')
		return (GREEN);
	if (c == 'y')
		return (YELLOW);
	if (c == 'b')
		return (BLUE);
	if (c == 'p')
		return (PURPLE);
	if (c == 'c')
		return (CYAN);
	if (c == 'g')
		return (GRAY);
	else
		return (NULL);
}

//	"X  c #174544"
//	"498 269 256 2 ",

//		\001\033[38;2;000;000;000m\002
//					  9-10-11;13-14-15;17-18-19

int	ft_get_max_colors(char *info)
{
	int	max;

	max = 100;
	(void)info;
	return (max);
}

char	*ft_extract_color(char *color_hexa)
{
	char	*color;
	char	tmp[3];
	int		value;
	int		i;
	int		j;

	tmp[3] = '\0';
	color = ft_strndup("\001\033[38;2;000;000;000m\002", 22);
	if (!color)
		return (NULL);
	i = 11;
	j = 8;
	while (*color_hexa)
	{
		tmp[0] = *color_hexa;
		tmp[1] = *(color_hexa + 1);
		color_hexa += 2;
		value = ft_atoi_base(tmp, "0123456789ABCDEF");
		while (i > j)
		{
			color[i] = value % 10 + '0';
			value /= 10;
			i--;
		}
		i += 7;
		j += 4;
	}
	return (color);
}

char	*ft_get_color_value(char c, char **color_table)
{
	char	*ptr;
	int		max_colors;
	char	*color;
	int		i;

	max_colors = ft_get_max_colors(color_table[0]);
	i = 1;
	while (i < max_colors && color_table[i][0] != c)
		i++;
	if (i == max_colors)
		return (NULL);
	ptr = ft_strchr(color_table[i], '#');
	if (!ptr)
		return (NULL);
	ptr++;
	color = ft_extract_color(ptr);
	return (color);
}

int	ft_color_table_n_color(char *pathname)
{
	char	buf[128];
	char	*ptr;
	int		fd;
	int		len;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (perror("Error "), -1);
	while (buf[0] != "\"" && n_read && n_read != -1)
		n_read = read(fd, &buf, 1);
	if (n_read == -1)
		return (close(fd), perror("Error"), -1);
	while (buf[++i] != "\"" && n_read && n_read != -1)
		n_read = read(fd, &buf[i], 1);
	if (n_read == -1)
		return (close(fd), perror("Error"), -1);
	buf[i] = 0;
	ptr = ft_strchr(buf, ' ') + 1;
	ptr = ft_strchr(ptr, ' ');
	len = ft_atoi(ptr);
	close (fd);
	return (len);
}

int	**ft_color_table_extract(char *pathname)
{
	int		**color_table;
	int		len;
	char	buf[128];
	char	*ptr;

	len = ft_color_table_n_color(pathname);
	if (len == -1)
		return (perror("Error "), NULL);
	color_table = ft_calloc(len, sizeof(void *));
	if (!color_table)
		return (perror("Error "), NULL);
	


	
}
