/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:36:03 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/10 22:20:42 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_here_doc(char *end);

int	main(int argc, char **argv, char **env)
{
	t_pipex	test;
	int		i;

	i = 0;
	test.n_cmd = argc - 3;
	test.env = env;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	test.fds[0] = 0;
	test.fds[1] = 1;
	if (!access(argv[1], F_OK | R_OK))
		test.fds[0] = open(argv[1], O_RDONLY |  O_CLOEXEC);
	if (!access(argv[argc - 1], F_OK | R_OK))
		test.fds[1] = open(argv[argc - 1], O_RDONLY |  O_CLOEXEC);
	pipe(test.pipefd[0]);
	pipe(test.pipefd[1]);
	ft_parsing(argv, env[i], &test);




	

	
	



	ft_clean_exit(&test, EXIT_SUCCESS);
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



 	i = 0;
	while (i < 2)
	{
		ft_printf("pipefd[%d][0] = %d\n", i, test.pipefd[i][0]);
		ft_printf("pipefd[%d][1] = %d\n", i, test.pipefd[i][1]);
		i++;
	}
	i = 0;
	while (i < test.n_cmd)
	{
		ft_printf("cmdio[%d][0] = %d\n", i, test.cmdio[i][0]);
		ft_printf("cmdio[%d][1] = %d\n", i, test.cmdio[i][1]);
		i++;
	}
 */