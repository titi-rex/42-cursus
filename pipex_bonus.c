/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:17:44 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/25 14:45:44 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	char	**cmd;
	
}
		/* cmd2 */
		cmd = ft_cmd_search(argv[3], env[6]);
		if (!cmd)
			ft_error("malloc fail\n", NULL);
		if (access(cmd[0], X_OK) == -1)
			ft_error("You're not authorized to use this command !\n", cmd);
		fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
		ft_cmd_exec(pipefd[0], fd, pipefd[1], cmd);
		ft_freesplit(cmd);


			chpid = 0;
	if (waitpid(chpid, NULL, 0) == chpid)
			return ;