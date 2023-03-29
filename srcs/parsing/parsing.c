/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/29 11:25:14 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_bloc_cmd(char *arg, t_line *line, t_list	*io)
{
	t_cmd	*cmds;
	char	**split;
	char	*tmp;
	int		i;

	i = 0;
	cmds = NULL;
	split = ft_split_bis(arg, " ");
	while (split[i])
	{
		tmp = ft_quotes_delete(split[i], 0, 0);
		if (!tmp)
			return (ft_bloc_cmd_free(split, i), 1);
		split[i] = tmp;
		split[i] = ft_bloc_clear_backslash(split[i]);
		if (!split[i])
			return (ft_bloc_cmd_free(split, i), 1);
		i++;
	}
	cmds = s_cmd_new_alloc(split, io);
	if (!cmds)
		return (ft_free2d((void **)split, 0), 1);
	s_cmd_add_back(&line->cmd, cmds);
	ft_free2d((void **)split, i);
	return (0);
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
	if (!bloc || error[0] == 1 || error[0] == 2)
	{
		if (bloc)
			free(bloc);
		else if (error[0] != 1)
			error[0] = 2;
		return (1);
	}
	if (ft_bloc_empty(bloc) == 2 && io == NULL)
	{
		error[0] = 1;
		return (free(bloc), error[1] = -1, 1);
	}
	if (ft_bloc_empty(bloc) == 1 && io == NULL)
		error[1] = -1;
	if (ft_bloc_cmd(bloc, line, io))
	{
		error[0] = 2;
		ft_free_secure(bloc);
		return (1);
	}
	free(bloc);
	return (0);
}

int	ft_bloc_manage_error(int *error, int *n_cmds)
{
	if (error[1] == -1 && *n_cmds == 1)
		*n_cmds = 0;
	if (error[1] == -1 && *n_cmds > 1)
		return (1);
	return (0);
}

int	ft_parse_line(char *str, int i, int start, t_line *line)
{
	char	*bloc;
	t_list	*io;
	int		error[2];

	ft_bloc_init(&io, error, &bloc);
	while (str[++i])
	{
		if (ft_quotes_error(str, &i, &error[0]) == 3)
			return (error[0]);
		if (str[i] == '|')
		{
			line->n_cmds += ft_bloc_separate(&str, &i, &start, &bloc);
			ft_bloc_format(&bloc, &io, &error[0], line);
			if (ft_bloc_fill_list(bloc, io, line, error) == 1)
				return (error[0]);
		}
		if (str[i] == '\0' || str[i + 1] == '\0')
		{
			line->n_cmds += ft_bloc_separate(&str, &i, &start, &bloc);
			ft_bloc_format(&bloc, &io, &error[0], line);
			if (ft_bloc_fill_list(bloc, io, line, error) == 1)
				return (error[0]);
		}
	}
	return (ft_bloc_manage_error(error, &(line->n_cmds)));
}
