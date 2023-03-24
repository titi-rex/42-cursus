/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:35:47 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/24 23:53:08 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//	"X  c #174544"
//	"498 269 256 2 ",

//		\001\033[38;2;000;000;000m\002
//					  9-10-11;13-14-15;17-18-19
int	ft_atoi_base(char *str, int base)
{
	(void)str;
	(void)base;
	return (1);
}

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

	tmp[3] = '\0';
	color = ft_strndup("\001\033[38;2;000;000;000m\002", 22);
	if (!color)
		return (NULL);
	i = 11;
	while (*color_hexa)
	{
		tmp[0] = *color_hexa;
		tmp[1] = *(color_hexa + 1);
		color_hexa += 2;
		value = ft_atoi_base(tmp, 16);
		while (value > 0)
		{
			color[i] = value % 10 + '0';
			value /= 10;
			i--;
		}
		i += 7;
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

char	*ft_get_color_4bit(char c)
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

char	*ft_set_color(char c, char **color_table)
{
	char	*color;

	if (!color_table)
		return (ft_get_color_4bit(ft_tolower(c)));
	color = ft_get_color_value(c, color_table);
	return (color);
}

int	ft_colorprint(char *str, char **color_table)
{
	char	*color;

	while (*str)
	{
		color = ft_set_color(*str, color_table);
		ft_putstr_fd(color, 1);
		if (*str != '\n' && *str != ' ')
			ft_putchar_fd('*', 1);
		else
			ft_putchar_fd(*str, 1);
		ft_putstr_fd(END, 1);
		str++;
	}
	ft_putchar('\n');
	(void)color_table;
	return (EXIT_SUCCESS);
}
