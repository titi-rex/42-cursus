/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:47:02 by louisa            #+#    #+#             */
/*   Updated: 2023/03/29 12:14:44 by lboudjem         ###   ########.fr       */
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

int	ft_redirection_hd(int *type, t_line *line, char **arg)
{
	int	dolls;

	dolls = 1;
	if (*type == 2)
	{
		if ((*arg)[0] == 39 || (*arg)[0] == 34)
			dolls = 0;
		*arg = ft_quotes_delete(*arg, 0, 0);
		*arg = ft_here_doc_mode(arg);
		if (*arg && dolls == 1)
			*arg = ft_exp_handle_heredoc(*arg, line);
	}
	return (0);
}

t_list	*ft_redirection_handle(char **bloc, int *err, t_line *line, int i)
{
	int			type;
	char		*arg;
	t_list		*io;

	ft_redirection_init(&i, &type, &arg, &io);
	while ((*bloc) && (*bloc)[++i])
	{
		ft_redirection_skip_quotes(bloc, &i);
		if (ft_redirection_type(*bloc, &type, &i) == -1)
			return (*err = 1, NULL);
		else if (ft_redirection_type(*bloc, &type, &i) == 1)
		{
			arg = ft_redirection_arg(*bloc, i);
			if (type != 2)
				arg = ft_quotes_delete(arg, 0, 0);
			if (!arg)
				return (*err = 2, io);
			*bloc = ft_redirection_clear(*bloc, i);
			ft_redirection_hd(&type, line, &arg);
			if (s_redirect_add_list(&io, type, arg))
				return (free(arg), *err = 2, io);
			i = -1;
		}
	}
	return (*err = 0, io);
}
