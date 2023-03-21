/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:47:02 by louisa            #+#    #+#             */
/*   Updated: 2023/03/21 19:47:12 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
	if (!bloc[i])
		return (NULL);
	if (bloc[i] == 34 || bloc[i] == 39)
	{
		i++;
		len++;
		while (bloc[i] != 34 && bloc[i] != 39)
		{
			i++;
			len++;
		}
	}
	while (bloc[i] != ' ' && bloc[i] != '\t' && bloc[i] != '\n' \
			&& bloc[i] != '\0' && bloc[i] != '>' && bloc[i] != '<')
	{
		len++;
		i++;
	}
	arg = ft_substr(bloc, tmp, len);
	arg = ft_delete_quotes(arg, 0, 0, 34);
	arg = ft_delete_quotes(arg, 0, 0, 39);
	return (arg);
}

int	ft_redirection_type_fd(char *bloc, int *type, int *i)
{
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
	if (bloc[*i] == '<' && bloc[(*i) + 1] != '<')
	{
		*type = 0;
		return (1);
	}
	if (bloc[*i] == '>' && bloc[(*i) + 1] != '>')
	{
		*type = 1;
		return (1);
	}
	return (0);
}

int	ft_size_redirection(char *bloc, int i, int len)
{
	while (bloc[i] == ' ' || bloc[i] == '\t' || bloc[i] == '\n' \
			|| bloc[i] == '>' || bloc[i] == '<')
	{
		len++;
		i++;
	}

	if (bloc[i] == 34 || bloc[i] == 39)
	{
		i++;
		len++;
		while (bloc[i] != 34 && bloc[i] != 39)
		{
			i++;
			len++;
		}
	}
	while (bloc[i] != ' ' && bloc[i] != '\t' && bloc[i] != '\n' \
			&& bloc[i] != '\0' && bloc[i] != '>' && bloc[i] != '<')
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_clear_redirection(char *bloc, int i)
{
	int		len;
	int		size;
	char	*cpy;
	char	*sub1;
	char	*sub2;

	cpy = NULL;
	len = ft_size_redirection(bloc, i, 0);
	size = ft_strlen2(bloc);
	sub1 = ft_substr(bloc, 0, i - 1);
	sub2 = ft_substr(bloc, i + len, size - (i + len));
	cpy = ft_strjoin(sub1, sub2);
	free(bloc);
	free(sub1);
	free(sub2);
	return (cpy);
}

t_list	*ft_handle_redirection(char **bloc, int *error)
{
	int			i;
	int			type;
	char		*arg;
	t_list		*io;

	i = 0;
	type = -1;
	io = NULL;
	arg = NULL;
	while ((*bloc) && (*bloc)[i])
	{
		if (ft_redirection_type_fd(*bloc, &type, &i) == 1)
		{
			dprintf(2, "type is : %d\n", type);
			arg = ft_redirection_arg(*bloc, i);
			if (!arg)
				return (*error = 1, NULL);
			*bloc = ft_clear_redirection(*bloc, i);
			ft_redirect_add_list(&io, type, arg);
			free(arg);
			if (!(*bloc)[0] || !(*bloc)[1])
				break ;
			i = 0;
		}
		i++;
	}
	return (*error = 0, io);
}
