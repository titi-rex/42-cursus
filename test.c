/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:36:03 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/06 16:43:42 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_here_doc(char *end);

int	main(void)
{
	ft_here_doc("end");
	return (0);
}


/*
 * 
 * 
 * 
 * 
 * 	char	*buffer;
	char	*line;

	line = NULL;
	buffer = (char *)ft_calloc(100, sizeof(char));
	while (ft_strncmp(buffer, "end", 3))
	{
		read(0, buffer, 100);
		line = ft_self_append(line, buffer);
	}
	ft_printf("line is %s\n", line);
	free(line);
 * 
 */