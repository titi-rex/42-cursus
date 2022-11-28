/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:14 by tlegrand          #+#    #+#             */
/*   Updated: 2022/11/28 18:02:57 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tmp;
	char		*buff;
	size_t		i;

	if (fd == -1)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	i = 0;
	tmp = NULL;
	while (read(fd, buff, BUFFER_SIZE))
	{
		printf("ici c ok0\n");
		tmp = ft_strjoin(tmp, buff);
		printf("ici c oknon?\n");
		if (ft_strchr(buff, '\n'))
			break ;
	}
	printf("ici c ok\n");
	while (tmp[i] && tmp[i] != '\n')
		i++;
	printf("ici c ok2\n");
	line = ft_substr(tmp, 0, i);
	printf("ici c ok3\n");
	tmp = ft_substr(tmp, ft_strlen(line), ft_strlen(tmp) - ft_strlen(line));
	printf("ici c ok4\n");
	free(buff);
	free(tmp);
	return (line);
}

int	main(void)
{
	char	*str;

	str = get_next_line(1);
	printf("\n: %s\n", str);
	return (0);
}
