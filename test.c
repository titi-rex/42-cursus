/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:36:03 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/25 17:03:17 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	spawnchild(void);

int	main(void)
{
	printf("parent's here %d\n", getpid());
	fork();
	printf("wtf! %d\n", getpid());

	return (0);
}

void	cmdchild1(void)
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