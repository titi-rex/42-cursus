/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:47:02 by louisa            #+#    #+#             */
/*   Updated: 2023/03/27 10:09:18 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_redirection_clear(char *bloc, int i)
{
	int		len;
	int		size;
	char	*cpy;
	char	*sub1;
	char	*sub2;

	cpy = NULL;
	len = ft_redirection_size(bloc, i, 0);
	size = ft_strlen2(bloc);
	sub1 = ft_substr(bloc, 0, i);
	sub2 = ft_substr(bloc, i + len, size - (i + len));
	cpy = ft_strjoin(sub1, sub2);
	free(bloc);
	free(sub1);
	free(sub2);
	return (cpy);
}

void	ft_redirection_init(int *i, int *type, char **arg, t_list **io)
{
	*i = 0;
	*type = -1;
	*io = NULL;
	*arg = NULL;
}

void	ft_redirection_skip_quotes(char **bloc, int *i)
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

int	ft_redirection_hd(int *type, int *error, t_line *line, char **arg)
{
	if (*type == 2)
	{
		*arg = ft_here_doc_mode(arg);
		if (!(*arg))
			return (*error = 1, 1);
		*arg = ft_exp_handle_heredoc(*arg, line);
	}
	return (0);
}

t_list	*ft_redirection_handle(char **bloc, int *error, t_line *line)
{
	int			i;
	int			type;
	char		*arg;
	t_list		*io;

	ft_redirection_init(&i, &type, &arg, &io);
	while ((*bloc) && (*bloc)[i])
	{
		ft_redirection_skip_quotes(bloc, &i);
		if (ft_redirection_type(*bloc, &type, &i) == -1)
			return (*error = 1, NULL);
		if (ft_redirection_type(*bloc, &type, &i) == 1)
		{
			arg = ft_redirection_arg(*bloc, i);
			if (!arg)
				return (*error = 1, NULL);
			*bloc = ft_redirection_clear(*bloc, i);
			if (ft_redirection_hd(&type, error, line, &arg) == 1)
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
