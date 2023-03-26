/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/26 13:02:40 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_bloc_cmd(char *arg, t_line *line, t_list	*io)
{
	t_cmd	*cmds;
	char	**split;
	int		i;

	i = 0;
	cmds = NULL;
	split = ft_split_bis(arg, ' ');
	while (split[i])
	{
		split[i] = ft_quotes_delete(split[i], 0, 0);
		i++;
	}
	cmds = ft_cmd_new_alloc(split, io);
	ft_cmd_add_back(&line->cmd, cmds);
	ft_free2d((void **)split, i);
}

char	*ft_bloc_creat(char *str, int *i, int *start, char *bloc)
{
	bloc = ft_substr(str, *start, *i - *start);
	*start = *i;
	while (str[*start] != '|')
		(*start)++;
	(*start)++;
	while (str[*start] == ' ')
		(*start)++;
	return (bloc);
}

int	ft_bloc_fill_list(char *bloc, t_list *io, t_line *line, int *error)
{
	if (!bloc || *error == 1)
		return (free(bloc), 1);
	if (ft_bloc_empty(bloc) == 1 && io == NULL)
		*error = -1;
	ft_bloc_cmd(bloc, line, io);
	free(bloc);
	return (0);
}

int	ft_parse_line(char *str, int i, int start, t_line *line)
{
	char	*bloc;
	t_list	*io;
	int		error;

	ft_bloc_init(&io, &error, &bloc);
	while (str[i])
	{
		ft_quotes_error(str, &i, &error);
		if (error == 2)
			return (2);
		if (str[i] == '|')
		{
			line->n_cmds += ft_bloc_separate(&str, &i, &start, &bloc);
			ft_bloc_format(&bloc, &io, &error, line);
			if (ft_bloc_fill_list(bloc, io, line, &error) == 1)
				return (1);
		}
		if (str[i] == '\0' || str[i + 1] == '\0')
		{
			line->n_cmds += ft_bloc_separate(&str, &i, &start, &bloc);
			ft_bloc_format(&bloc, &io, &error, line);
			if (ft_bloc_fill_list(bloc, io, line, &error) == 1)
				return (1);
		}
		i++;
	}
	if (error == -1 && line->n_cmds == 1)
		line->n_cmds = 0;
	if (error == -1 && line->n_cmds > 1)
		return (1);
	return (0);
}
