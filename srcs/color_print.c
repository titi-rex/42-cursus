/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:35:47 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/25 13:23:24 by tlegrand         ###   ########.fr       */
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

char	*ft_set_color(char c, char **color_table)
{
	char	*color;

	if (!color_table)
		return (ft_color_table_3bit(ft_tolower(c)));
	color = NULL;//ft_get_color_value(c, color_table);
	return (color);
}

int	ft_colorprint(char *str, char **color_table)
{
	char	*color;

	while (*str)
	{
		color = ft_color_table_3bit(*str);
		ft_putstr_fd(color, 1);
		ft_putchar_fd(*str, 1);
		str++;
	}
	ft_putstr_fd(END, 1);
	ft_putchar('\n');
	(void)color_table;
	return (EXIT_SUCCESS);
}
