/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/11 16:57:02 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_replace_expansion_value(char *bloc, t_line *line, int len)
{
	char	*name;
	char	*value;

	name = malloc((len + 1) * sizeof(char));
	if (!name)
		return (NULL);
	value = ft_strdup(get_value(line->lst_env, name));
	printf("value = %s\n", value);
	(void)bloc;
	return (value);
}

char	*ft_replace_by_exit_status(char *bloc, int i, t_line *line)
{
	char	*exit_s;
	char	*cpy;
	int		len;
	int		tmp;

	tmp = i + 2;
	exit_s = ft_itoa(line->exit_status);
	if (!exit_s)
		return (NULL);
	len = (int)(ft_strlen2(bloc)) - 2 + ft_strlen2(exit_s);
	cpy = malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, bloc, i + 1);
	len = 0;
	while (exit_s[len])
		cpy[i++] = exit_s[len++];
	i++;
	printf("bloc[tmp] = %c\n", bloc[tmp]);
	while (bloc[tmp])
	{
		cpy[i] = bloc[tmp];
		i++;
		printf("1");
		tmp++;
	}
	cpy[i] = '\0';
	printf("cpy = %s\n", cpy);
	//free(bloc);
	return (cpy);
}

void	ft_handle_expansion(char *bloc, t_line *line)
{
	int		i;
	int		name_len;
	char	*name;

	i = 0;
	name_len = 0;
	while (bloc[i])
	{
		if (bloc[i] == 39)
			while (bloc[i] != 39)
				i++;
		if (bloc[i] == '$' && bloc[i + 1] == '?')
			bloc = ft_replace_by_exit_status(bloc, i, line);
		if (bloc[i] == '$')
		{
			i++;
			while (bloc[i++] != ' ')
				name_len++;
			//bloc = ft_replace_by_value(bloc, name_len);
		}
		i++;
	}
	(void)name;
	(void)line;
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
			printf("bloc = %s\n", bloc);
			ft_handle_expansion(bloc, line);
			free(bloc);
		}
		if (str[i] == '\0' || str[i + 1] == '\0')
		{
			bloc = ft_substr(str, start, (i + 1) - start);
			printf("bloc = %s\n", bloc);
			free(bloc);
		}
		i++;
	}
}
