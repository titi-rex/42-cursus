/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/25 18:34:59 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_creat_bloc(char *str, int *i, int *start, char *bloc)
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

int	ft_fill_list(char *bloc, t_list *io, t_line *line, int *error)
{
	if (!bloc || *error == 1)
		return (free(bloc), 1);
	if (ft_is_bloc_empty(bloc) == 1 && io == NULL)
		*error = -1;
	ft_list_cmd(bloc, line, io);
	free(bloc);
	return (0);
}

int	ft_browse_line(char *str, int i, int start, t_line *line)
{
	char	*bloc;
	t_list	*io;
	int		error;

	init_bloc(&io, &error, &bloc);
	while (str[i])
	{
		ft_quotes(str, &i, &error);
		if (error == 2)
			return (2);
		if (str[i] == '|')
		{
			line->n_cmds += separate_bloc(&str, &i, &start, &bloc);
			format_bloc(&bloc, &io, &error, line);
			if (ft_fill_list(bloc, io, line, &error) == 1)
				return (1);
		}
		if (str[i] == '\0' || str[i + 1] == '\0')
		{
			line->n_cmds += separate_bloc(&str, &i, &start, &bloc);
			format_bloc(&bloc, &io, &error, line);
			if (ft_fill_list(bloc, io, line, &error) == 1)
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
