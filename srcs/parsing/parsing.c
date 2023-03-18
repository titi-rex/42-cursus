/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/18 17:18:53 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_handle_export(char *bloc)
{
	int	i;

	i = 0;
	while (bloc[i])
	{
		if(ft_strncmp(bloc, "export", 6) == 0)
		{
			i += 6;
			while (bloc[i] && (bloc[i] == ' ' || bloc[i] == '\t' || bloc[i] == '\n'))
				i++;
			while (bloc[i] && (bloc[i] != ' ' && bloc[i] != '\t' && bloc[i] != '\n'))
			{
				if (bloc[i] == '=')
					bloc[i] = ' ';
				i++;
			}
		}
		i++;
	}
	return (bloc);
}

void	ft_list_cmd(char *arg, t_line *line, t_list	*io)
{
	t_cmd	*cmds;
	char	**split;
	int		i;
	int		j;
	char	quote;

	i = 0;
	cmds = NULL;
	split = ft_split_bis(arg, ' ');
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (split[i][j] == 34)
			{
				quote = 34;
				break ;
			}
			if (split[i][j] == 39)
			{
				quote = 39;
				break ;
			}
			j++;
		}
		//printf("split[i] = %s\n", split[i]);
		if (quote == 34 || quote == 39)
			split[i] = ft_delete_quotes(split[i], 0, 0, quote);
		//printf("split[i].2 = %s\n", split[i]);
		i++;
	}
	cmds = ft_cmd_new_alloc(split, io);
	ft_get_path(get_value(line->lst_env, "PATH"), cmds);
	ft_cmd_add_back(&line->cmd, cmds);
	//printf("arg = %s\n", ft_redirect_acces_arg(line->cmd->io->content));
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
			io = ft_handle_redirection(&bloc, &error);
			bloc = ft_handle_export(bloc);
			//printf("bloc = %s\n", bloc);
			if (error == 1)
				return (1);
			line->n_cmds++;
			ft_list_cmd(bloc, line, io);
			free(bloc);
		}
		if (str[i] == '\0' || str[i + 1] == '\0')
		{
			bloc = ft_substr(str, start, (i + 1) - start);
			bloc = ft_handle_expansion(bloc, line);
			io = ft_handle_redirection(&bloc, &error);
			bloc = ft_handle_export(bloc);
			//printf("bloc = %s\n", bloc);
			if (error == 1)
				return (1);
			line->n_cmds++;
			ft_list_cmd(bloc, line, io);
			free(bloc);
		}
		i++;
	}
	return (0);
}
