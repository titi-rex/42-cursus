/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/21 11:19:22 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	get_nb_quotes(char *bloc, int i)
{
	int	nb;

	nb = 0;
	while (bloc[i])
	{
		if (bloc[i] == 34)
		{
			nb++;
			i++;
			while (bloc[i] != 34)
				i++;
			nb++;
		}
		if (bloc[i] == 39)
		{
			nb++;
			i++;
			while (bloc[i] != 39)
				i++;
			nb++;
		}
		i++;
	}
	return (nb);
}

char	*ft_del_quotes(char *bloc)
{
	char	*cpy;
	int		size;
	int		nb_quotes;
	int		i;
	int		j;

	i = 0;
	j = 0;
	nb_quotes = get_nb_quotes(bloc, 0);
	size = ft_strlen2(bloc) - nb_quotes;
	cpy = malloc((size + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (bloc[i])
	{
		if (bloc[i] != 34 && bloc[i] != 39)
		{
			cpy[j] = bloc[i];
			j++;
		}
		if (bloc[i] == 34)
		{
			i++;
			while (bloc[i] != 34)
			{
				cpy[j] = bloc[i];
				j++;
				i++;
			}
		}
		if (bloc[i] == 39)
		{
			i++;
			while (bloc[i] != 39)
			{
				cpy[j] = bloc[i];
				j++;
				i++;
			}
		}
		i++;
	}
	cpy[j] = '\0';
	free(bloc);
	return (cpy);
}

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
	ft_get_path(get_value(line->lst_env, "PATH"), cmds);
	ft_cmd_add_back(&line->cmd, cmds);
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
			if (!bloc)
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
			if (!bloc)
				return (1);
			line->n_cmds++;
			ft_list_cmd(bloc, line, io);
			free(bloc);
		}
		i++;
	}
	return (0);
}
