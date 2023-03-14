/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/14 16:08:13 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// 5> test$ segfault

char	*ft_redirection_arg(char *bloc, int i)
{
	int		len;
	char	*arg;

	len = 0;
	while (bloc[i] == ' ' || bloc[i] == '\t' || bloc[i] == '\n')
		i++;
	//printf("bloc[i] = %c\n", bloc[i]);
	while (bloc[i] != ' ' || bloc[i] != '\t' || bloc[i] != '\n')
		len++;
	//printf("len = %d\n", len);
	arg = ft_substr(bloc, i, len);
	return (arg);
}

// si on supprime le fd la fonction est super courte ! et c cool :)
void	ft_redirection_type_fd(char *bloc, int *type, int *i, int *fd)
{
	if (bloc[*i] == '<')
	{
		if (*fd == -1)
			*fd = 0;
		*type = 0;
	}
	if (bloc[*i] == '>')
	{
		if (*fd == -1)
			*fd = 1;
		*type = 1;
	}
	if (ft_strncmp(&bloc[*i], "<<", 2) == 0)
	{
		if (*fd == -1)
			*fd = 0;
		*type = 2;
		(*i)++;
	}
	if (ft_strncmp(&bloc[*i], ">>", 2) == 0)
	{
		if (*fd == -1)
			*fd = 1;
		*type = 3;
		(*i)++;
	}
	(*i)++;
}

void	ft_handle_redirection(char *bloc)
{
	int		i;
	int		type;
	int		fd;
	char	*arg;

	i = 0;
	type = -1;
	fd = -1;
	while(bloc[i])
	{
		ft_redirection_type_fd(bloc, &type, &i, &fd);
		//arg = ft_redirection_arg(bloc, i);
		printf("type = %d\n", type);
		printf("fd = %d\n", fd);
		i++;
	}
	//printf("arg = %s\n", arg);
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
