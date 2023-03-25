/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:47:02 by louisa            #+#    #+#             */
/*   Updated: 2023/03/25 13:58:40 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_clear_redirection(char *bloc, int i, int type)
{
	int		len;
	int		size;
	char	*cpy;
	char	*sub1;
	char	*sub2;

	cpy = NULL;
	len = ft_size_redirection(bloc, i, 0);
	size = ft_strlen2(bloc);
	if (type == 2 || type == 3)
		sub1 = ft_substr(bloc, 0, i - 1);
	else if (type == 0 || type == 1)
		sub1 = ft_substr(bloc, 0, i);
	sub2 = ft_substr(bloc, i + len, size - (i + len));
	cpy = ft_strjoin(sub1, sub2);
	free(bloc);
	free(sub1);
	free(sub2);
	return (cpy);
}

void	ft_init_redirection(int *i, int *type, char **arg, t_list **io)
{
	*i = 0;
	*type = -1;
	*io = NULL;
	*arg = NULL;
}

void	ft_skip_quote_i(char **bloc, int *i)
{
	if ((*bloc)[*i] == 34)
	{
		(*i)++;
		while ((*bloc)[*i] && (*bloc)[*i] != 34)
			(*i)++;
	}
	if ((*bloc)[*i] == 39)
	{
		(*i)++;
		while ((*bloc)[*i] && (*bloc)[*i] != 39)
			(*i)++;
	}
}

int	here_doc_redir(int *type, int *error, t_line *line, char **arg)
{
	if (*type == 2)
	{
		*arg = ft_here_doc_mode(arg);
		if (!(*arg))
			return (*error = 1, 1);
		*arg = ft_handle_expansion_hd(*arg, line);
	}
	return (0);
}

t_list	*ft_handle_redirection(char **bloc, int *error, t_line *line)
{
	int			i;
	int			type;
	char		*arg;
	t_list		*io;

	ft_init_redirection(&i, &type, &arg, &io);
	while ((*bloc) && (*bloc)[i])
	{
		ft_skip_quote_i(bloc, &i);
		if (ft_redirection_type_fd(*bloc, &type, &i) == 1)
		{
			arg = ft_redirection_arg(*bloc, i);
			if (!arg)
				return (*error = 1, NULL);
			*bloc = ft_clear_redirection(*bloc, i, type);
			if (here_doc_redir(&type, error, line, &arg) == 1)
				return (NULL);
			ft_redirect_add_list(&io, type, arg);
			if (!(*bloc)[0] || !(*bloc)[1])
				break ;
			i = 0;
		}
		i++;
	}
	return (*error = 0, io);
}
