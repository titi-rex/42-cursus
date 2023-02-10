/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:36:03 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/10 16:49:36 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_here_doc(char *end);

int	main(int argc, char **argv, char **env)
{
	t_pipex	test;
	int		i;
	int		j;

	i = 0;
	test.n_cmd = argc - 3;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;

	ft_parsing(argv, &test, env[i]);
	ft_free3d((void ***) test.cmds, 0, NULL);


	exit(0);
	return (0);
}



void	printsplit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		ft_printf("%s ", split[i]);
		i++;
	}
	ft_printf("\n");
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