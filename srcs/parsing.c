/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/15 15:49:44 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// 5> test$ segfault

char	*ft_redirection_arg(char *bloc, int i)
{
	int		len;
	int		tmp;
	char	*arg;

	len = 0;
	while (bloc[i] == ' ' || bloc[i] == '\t' || bloc[i] == '\n' \
			|| bloc[i] == '>' || bloc[i] == '<')
		i++;
	tmp = i;
	while (bloc[i] != ' ' && bloc[i] != '\t' && bloc[i] != '\n' \
			&& bloc[i] != '\0' && bloc[i] != '>' && bloc[i] != '<')
	{
		len++;
		i++;
	}
	arg = ft_substr(bloc, tmp, len);
	return (arg);
}

int	ft_redirection_type_fd(char *bloc, int *type, int *i)
{
	if (bloc[*i] == '<')
	{
		*type = 0;
		return (1);
	}
	if (bloc[*i] == '>')
	{
		*type = 1;
		return (1);
	}
	if (ft_strncmp(&bloc[*i], "<<", 2) == 0)
	{
		*type = 2;
		(*i)++;
		return (1);
	}
	if (ft_strncmp(&bloc[*i], ">>", 2) == 0)
	{
		*type = 3;
		(*i)++;
		return (1);
	}
	return (0);
}

t_redirect	*ft_handle_redirection(char *bloc)
{
	int			i;
	int			type;
	int			fd;
	char		*arg;
	t_redirect	*io;

	i = 0;
	type = -1;
	fd = 0;
	arg = NULL;
	while(bloc[i])
	{
		if (ft_redirection_type_fd(bloc, &type, &i) == 1)
		{
			arg = ft_redirection_arg(bloc, i);
			printf("arg = %s\n", arg);
			io = ft_redirect_new(type, fd, arg); //retirer le fd
			free(arg);
			i++;
		}
		i++;
	}
	return (io);
	(void)io;
	(void)arg;
}

void	ft_browse_line(char *str, int i, int start, t_line *line)
{
	char	*bloc;

	bloc = NULL;
	while (str[i])
	{
		ft_quotes(str, &i);
		if (str[i] == '|')
		{
			bloc = ft_creat_bloc(str, &i, &start, bloc);
			ft_handle_expansion(&bloc, line);
			ft_handle_redirection(bloc);
			printf("bloc = %s\n", bloc);
			free(bloc);
		}
		if (str[i] == '\0' || str[i + 1] == '\0')
		{
			bloc = ft_substr(str, start, (i + 1) - start);
			ft_handle_expansion(&bloc, line);
			ft_handle_redirection(bloc);
			printf("bloc = %s\n", bloc);
			free(bloc);
		}
		i++;
	}
}
