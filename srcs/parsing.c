/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/11 16:07:12 by lboudjem         ###   ########.fr       */
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
			ft_replace_by_exit_status(bloc, i);
		if (bloc[i] == '$')
		{
			i++;
			while (bloc[i++] != ' ')
				name_len++;
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
