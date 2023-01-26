/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:30:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/26 15:11:02 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* need to make a better error management */
/* check if tmpfile exist before unlink */
int	main(int argc, char **argv, char **env)
{
	if (argc < 5)
		return(ft_man());
	if (!ft_strncmp(argv[1], "here_doc", 9))
		ft_append_mode(argc, argv, env[6]);
	else
		ft_normal_mode(argc, argv, env[6]);
	//if (unlink(PIPEX_TMP_FILE))
	//		ft_putstr_fd("Error deletion tmp file (pipex)\n", 2);
	return (0);
}

void	ft_normal_mode(int argc, char **argv, char *pathvar)
{
	int	i;

	i = 2;
	ft_printf("normal mode laucnhed\n");
	while (i < argc - 1)
	{
		if (i == 2)
			ft_cmd_master(argv[i], argv[1], PIPEX_TMP_FILE, pathvar);
		else if (i == argc - 2)
			ft_cmd_master(argv[i], PIPEX_TMP_FILE, argv[argc - 1], pathvar);
		else
			ft_cmd_master(argv[i], PIPEX_TMP_FILE, PIPEX_TMP_FILE, pathvar);
		i++;
	}
}
void	ft_append_mode(int argc, char **argv, char *pathvar)
{
	int	i;

	i = 3;
	ft_printf("append mode laucnhed\n");
	while (i < argc - 1)
	{
		if (i == 3)
			ft_cmd_master(argv[i], NULL, PIPEX_TMP_FILE, pathvar);
		else if (i == argc - 2)
			ft_cmd_master(argv[i], PIPEX_TMP_FILE, argv[argc - 1], pathvar);
		else
			ft_cmd_master(argv[i], PIPEX_TMP_FILE, PIPEX_TMP_FILE, pathvar);
		i++;
	}
}

int	ft_man(void)
{
	ft_printf("use me correctly u stupid nerd!\n");
	return (0);
}

void	ft_cmd_master(char *cmd_raw, char *file1, char *file2, char *pathvar)
{
	char	**cmd;

	cmd = ft_cmd_search(cmd_raw, pathvar);
	if (!cmd)
		ft_error("malloc fail\n", NULL);
	if (access(cmd[0], X_OK) == -1)
		ft_error("You're not authorized to use this command !\n", cmd);
	ft_cmd_exec(file1, file2, cmd);
	ft_printf("END %s\n", cmd[0]);
	ft_freesplit(cmd);
}

/*

valgrind --track-fd=yes ./exe
*/