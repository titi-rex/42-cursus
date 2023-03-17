/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/17 20:17:42 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**get_cmd(char *str, t_line *line)
{
	(void)str;
	line->cmd->arg = ft_split(str, ' ');
	if (!line->cmd->arg)
		return (NULL);
	return (line->cmd->arg);
}

int	ft_prompt(t_line *line)
{
	char	*str;
	char	**cmd;

	while (1)
	{
		str = readline("\033[1;35m$> \033[0m");
		if (!str)
			return (1);
		ft_browse_line(str, 0, 0, line);
		cmd = get_cmd(str, line);
		//ft_get_path(line->path, line->cmd);
		if (!cmd)
			return (1);
	}
}
/*
int	main(int argc, char **argv, char **env)
{
	t_line	line;
	t_cmd	arg;
	int		i;

	i = 0;
	(void)argc;
	(void)argv;
	line.cmd = &arg;
	line.env = env;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	line.path = env[i];
	fill_lst_env(&line, 0);
	//print_env(line.lst_env);
	//ft_envclear(&line.lst_env);
	if (ft_prompt(&line) == 1)
		return (1);
	ft_get_path(env[i], line.cmd);
	return (0);
}
*/