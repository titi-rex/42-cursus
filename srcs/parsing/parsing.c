/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/24 16:18:53 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_list_cmd(char *arg, t_line *line, t_list	*io)
{
	t_cmd	*cmds;
	char	**split;
	int		i;

	i = 0;
	cmds = NULL;
	//dprintf(2, "bloc :%s:\n", arg);
	split = ft_split_bis(arg, ' ');
	//ft_print_cmd_arg(split);
	while (split[i])
	{
		split[i] = ft_del_quotes(split[i]);
		i++;
	}
	cmds = ft_cmd_new_alloc(split, io);
	ft_cmd_add_back(&line->cmd, cmds);
	ft_free2d((void **)split, i);
}

int	ft_is_block_empty(char *bloc)
{
	int	i;

	i = 0;
	while (bloc[i])
	{
		if (bloc[i] != ' ' && bloc[i] != '\t' && \
			bloc[i] != '\n' && bloc[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_browse_line(char *str, int i, int start, t_line *line)
{
	char	*bloc;
	t_list	*io;
	int		error;
	int		null_error;

	io = NULL;
	null_error = 0;
	bloc = NULL;
	error = 0;
	while (str[i])
	{
		ft_quotes(str, &i, &error);
		if (error == 2)
			return (2);
		if (str[i] == '|')
		{
			bloc = ft_creat_bloc(str, &i, &start, bloc);
			bloc = ft_handle_expansion(bloc, line);
			io = ft_handle_redirection(&bloc, &error, line);
			bloc = ft_handle_export(bloc);
			//printf("bloc = %s\n", bloc);
			if (!bloc || error == 1)
				return (free(bloc), 1);
			if (ft_is_block_empty(bloc) == 1 && io == NULL)
				null_error = 1;
			line->n_cmds++;
			ft_list_cmd(bloc, line, io);
			free(bloc);
		}
		if (str[i] == '\0' || str[i + 1] == '\0')
		{
			bloc = ft_substr(str, start, (i + 1) - start);
			bloc = ft_handle_expansion(bloc, line);
			io = ft_handle_redirection(&bloc, &error, line);
			bloc = ft_handle_export(bloc);
			//printf("bloc = %s\n", bloc);
			if (!bloc || error == 1)
				return (free(bloc), 1);
			if (ft_is_block_empty(bloc) == 1 && io == NULL)
				null_error = 1;
			line->n_cmds++;
			ft_list_cmd(bloc, line, io);
			free(bloc);
		}
		i++;
	}
	if (null_error == 1 && line->n_cmds == 1)
		line->n_cmds = 0;
	if (null_error == 1 && line->n_cmds > 1)
		return (1);
	return (0);
}
