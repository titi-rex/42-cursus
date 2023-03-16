/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/16 16:25:57 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_list_cmd(char *arg, t_line *line, t_list	*io)
{
	t_cmd	*cmds;
	char	**split;

	cmds = NULL;
	split = ft_split(arg, ' ');
	cmds = ft_cmd_new_alloc(split, io);
	line->cmd = cmds;
	//printf("arg = %s\n", ft_redirect_acces_arg(line->cmd->io->content));
	(void)line;
	(void)cmds;
}

int	ft_browse_line(char *str, int i, int start, t_line *line)
{
	char	*bloc;
	t_list	*io;
	int		error;

	io = NULL;
	bloc = NULL;
	error = 0;
	while (str[i])
	{
		ft_quotes(str, &i);
		if (str[i] == '|')
		{
			bloc = ft_creat_bloc(str, &i, &start, bloc);
			bloc = ft_handle_expansion(bloc, line);
			io = ft_handle_redirection(bloc, &error);
			if (error == 1)
				return (1);
			printf("bloc = %s\n", bloc);
			ft_list_cmd(bloc, line, io);
			free(bloc);
		}
		if (str[i] == '\0' || str[i + 1] == '\0')
		{
			bloc = ft_substr(str, start, (i + 1) - start);
			bloc = ft_handle_expansion(bloc, line);
			io = ft_handle_redirection(bloc, &error);
			if (error == 1)
				return (1);
			printf("bloc = %s\n", bloc);
			ft_list_cmd(bloc, line, io);
			free(bloc);
		}
		i++;
	}
	return (0);
}

// void	ft_parsing()
// {
	
// }
