/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:14 by tlegrand          #+#    #+#             */
/*   Updated: 2022/11/29 18:39:17 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff2;
	static char	*tmp;
	char		buff[BUFFER_SIZE + 1];
	size_t		i;
	int			len;

	if (fd == -1)
		return (NULL);
	buff[BUFFER_SIZE] = 0;
//	printf("first tmp :%s:\n", tmp);
	len = 1;
	if (!ft_strchr(tmp, '\n') && len)
		printf("pas retour ligne trouver in tmp et len != 0\n");
	while (!ft_strchr(tmp, '\n') && (len = read(fd, buff, BUFFER_SIZE)) != 0)
	{
		printf("len :%d\n", len);
		printf("buff :%s:\n", buff);
		tmp = ft_strjoin(tmp, buff);
//		printf("tmp :%s:\n", tmp);
		if (ft_strchr(tmp, '\n'))
		{
//			printf("break\n");
			break ;
		}
	}
//	printf("tmp finale :%s:fin tmp\n", tmp);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
//	printf("ii : %zu\n", i);
//	printf("0strlen(tmp) = %zu\nstart = %zu\n", ft_strlen(tmp), i + 1);
	buff2 = ft_substr(tmp, 0, ft_strlen(tmp));
	line = ft_substr(buff2, 0, i);
//	printf("subs :%s:\n", ft_substr(tmp, i + 1, ft_strlen(tmp) - i));
//	printf("strlen(tmp) = %zu\nstart = %zu\n", ft_strlen(tmp), i + 1);
	tmp = ft_substr(tmp, i + 1, ft_strlen(tmp));
//	printf("2strlen(tmp) = %zu\nstart = %zu\n", ft_strlen(tmp), i + 1);
//	printf("tmp after sub:%s:\n", tmp);
	free(tmp);
//	printf("tmp after free :%s:\n", tmp);
	return (line);
}

int	main(void)
{
	char	*str;
	int		i;
	int		fd;

	fd = open("file", O_RDONLY);
	i = 0;
	while (i < 5)
	{
		str = get_next_line(fd);
		printf("\n:%s:\n", str);
		i++;
	}
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
