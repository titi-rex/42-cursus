/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bloc_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:59:18 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/25 13:00:30 by lboudjem         ###   ########.fr       */
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
	split = ft_split_bis(arg, ' ');
	while (split[i])
	{
		split[i] = ft_del_quotes(split[i]);
		i++;
	}
	cmds = ft_cmd_new_alloc(split, io);
	ft_cmd_add_back(&line->cmd, cmds);
	ft_free2d((void **)split, i);
}

int	ft_is_bloc_empty(char *bloc)
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

void	init_bloc(t_list **io, int *error, char **bloc)
{
	*io = NULL;
	*bloc = NULL;
	*error = 0;
}

void	separate_bloc(char **str, int *i, int *start, char **bloc)
{
	if ((*str)[*i] == '|')
		*bloc = ft_creat_bloc(*str, i, start, *bloc);
	else if ((*str)[*i] == '\0' || (*str)[(*i) + 1] == '\0')
		*bloc = ft_substr(*str, *start, ((*i) + 1) - *start);
}

void	format_bloc(char **bloc, t_list **io, int *error, t_line *line)
{
	*bloc = ft_handle_expansion(*bloc, line);
	*io = ft_handle_redirection(bloc, error, line);
	*bloc = ft_handle_export(*bloc);
}
