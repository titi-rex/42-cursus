/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_redirection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:42:09 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/26 12:03:00 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_skip_both_quotes(int *i, int *len, char *bloc)
{
	if (bloc[*i] == 34 || bloc[*i] == 39)
	{
		(*i)++;
		(*len)++;
		while (bloc[*i] && bloc[*i] != 34 && bloc[*i] != 39)
		{
			(*i)++;
			(*len)++;
		}
	}
}

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
	ft_skip_both_quotes(&i, &len, bloc);
	while (bloc[i] != ' ' && bloc[i] != '\t' && bloc[i] != '\n' \
			&& bloc[i] != '\0' && bloc[i] != '>' && bloc[i] != '<')
	{
		len++;
		i++;
	}
	arg = ft_substr(bloc, tmp, len);
	arg = ft_quotes_delete(arg, 0, 0);
	return (arg);
}

int	ft_redirection_type(char *bloc, int *type, int *i)
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

int	ft_redirection_size(char *bloc, int i, int len)
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
