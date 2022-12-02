/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:56:05 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/02 18:21:32 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
int    main(void)
{
    int        fd;
    char    *line;

    // fd = open("test.txt", O_RDONLY);
    fd = open("/Users/tlegrand/francinette/tests/get_next_line/fsoares/read_error.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("line1: |%s|\n", line);
    free(line);
    line = get_next_line(fd);
    printf("line2: |%s|\n", line);
    free(line);
    if (BUFFER_SIZE > 100)
    {
        char *temp;
        do {
            temp = get_next_line(fd);
            printf("temp: |%s|\n", temp);
            free(temp);
        } while (temp != NULL);
    }
    line = get_next_line(fd);
    printf("line3: |%s|\n", line);
    free(line);
    close(fd);
    fd = open("/Users/tlegrand/francinette/tests/get_next_line/fsoares/read_error.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("line4: |%s|\n", line);
    free(line);
    line = get_next_line(fd);
    printf("line5: |%s|\n", line);
    free(line);
    line = get_next_line(fd);
    printf("line6: |%s|\n", line);
    free(line);
    line = get_next_line(fd);
    printf("line7: |%s|\n", line);
    free(line);
    line = get_next_line(fd);
    printf("line8: |%s|\n", line);
    free(line);
}*/


int	main(void)
{
	char	*str;
	int		i;
	int		fd;

	fd = open("file", O_RDONLY);
	i = 0;
	while (i < 6)
	{
		str = get_next_line(fd);
		printf("\n:%p:\n", str);
		i++;
	}
	free(str);
	close(fd);
	// i = 0;
	// while (i < 3)
	// {
	// 	str = get_next_line(1);
	// 	printf("\n:%s:\n", str);
	// 	i++;
	// }
	return (0);
}
