/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:36:03 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/09 15:10:50 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_here_doc(char *end);

int	main(int argc, char **argv, char **env)
{
	char	**test;
	int		i;
	
		i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	test = ft_split_path(env[i], ':');
	i = 0;
	while(test[i])
	{
		ft_printf("splitpath[%d] is %s\n", i, test[i]);
		i++;
	}
	ft_freesplit(test);
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