/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:16:07 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/12 20:14:37 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	ft_man(void);

int	main(int argc, char **argv, char **env)
{
	t_pipex	cmd_line;

	if (argc < 5)
		ft_man();
	cmd_line.env = env;
	if ((!ft_strncmp(argv[1], "here_doc", 9)))
	{
		ft_parsing(argv, argc, 3, &cmd_line);
		ft_here_doc(argv[2], &cmd_line);
		printpipex(&cmd_line);
		ft_cmd_master(&cmd_line);
	}
	else
	{
		ft_parsing(argv, argc, 2, &cmd_line);
		ft_cmd_master(&cmd_line);
	}
	ft_clean_exit(&cmd_line, EXIT_SUCCESS);
	return (0);
}

static void	ft_man(void)
{
	ft_printf("use me correctly u stupid nerd!\n");
	ft_printf("Like that (2 or more cmds) : ");
	ft_printf("./pipex input_file cmd1 cmd2... last_cmd output_file\n");
	ft_printf("Or with here_doc : ");
	ft_printf("./pipex here_doc LIMITER cmd1 cmd2 output_file\n");
	ft_printf("Or both : ");
	ft_printf("./pipex here_doc LIMITER cmd1 cmd2... last_cmd output_file\n");
	exit(EXIT_SUCCESS);
}

/*
bug heredoc du caca quii reste 
check behavior when error
doc
makefile
*/