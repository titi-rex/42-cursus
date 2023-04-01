/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:36:37 by tlegrand          #+#    #+#             */
/*   Updated: 2023/04/01 11:52:19 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **arg)
{
	int		fd;
	char	*line;

	if (ac != 2)
		return (1);
	fd = open(arg[1], O_RDONLY);
	if (fd == -1)
		return (perror("Error "), 1);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		printf(":%s:", line);
		if (line)
			free(line);
	}
	printf("\nEND\n");
}
