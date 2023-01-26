/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:36:03 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/26 15:48:53 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	cmdchild1(void);

int	main(void)
{
	char	*buffer;
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
	return (0);
}

void	cmdchild1(void)
{
	int		chpid;
	char	*cmd[4];

	cmd[0] = "/usr/bin/cat";
	cmd[1] = "<<";
	cmd[2] = "end";
	cmd[3] = NULL;
	chpid = fork();
	waitpid(chpid, NULL, 0);
	if (chpid == 0)
	{
		printf("child %d\n", getpid());
		chpid = fork();
		waitpid(chpid, NULL, 0);
		if (chpid == 0)
			execve(cmd[0], cmd, NULL);
		printf("child end\n");
		exit(EXIT_SUCCESS);
	}
}

void	cmdchild2(void)
{
	int		chpid;
	char	*cmd[3];

	cmd[0] = "/usr/bin/grep";
	cmd[1] = "heart";
	cmd[2] = NULL;
	chpid = fork();
	waitpid(chpid, NULL, 0);
	if (chpid == 0)
	{
		printf("child %d\n", getpid());
		chpid = fork();
		waitpid(chpid, NULL, 0);
		if (chpid == 0)
			execve(cmd[0], cmd, NULL);
		printf("child end\n");
		exit(EXIT_SUCCESS);
	}
}