/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_expansion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:53:50 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/29 12:28:20 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_exp_replace_value(char *bloc, t_line *line, int len, int i)
{
	char	*value;
	char	*cpy;
	int		size;
	int		tmp;

	value = ft_exp_get_value(bloc, line, &len, i + 1);
	value = ft_bloc_protect_backslash(value);
	value = ft_export_protect_quotes(value);
	value = ft_export_protect_dolls(value);
	size = ft_strlen2(bloc) - len + ft_strlen2(value);
	cpy = ft_calloc((size + 1), sizeof(char));
	if (!cpy)
		return (free(bloc), ft_free_secure(value));
	tmp = i + len + 1;
	ft_strlcpy(cpy, bloc, i + 1);
	size = 0;
	if (value)
		while (value[size])
			cpy[i++] = value[size++];
	while (bloc && bloc[tmp])
		cpy[i++] = bloc[tmp++];
	free(bloc);
	free(value);
	return (cpy);
}

char	*ft_exp_replace_exit_status(char *bloc, int i, t_line *line)
{
	char	*exit_s;
	char	*cpy;
	int		len;
	int		tmp;

	if (!bloc)
		return (NULL);
	tmp = i + 2;
	exit_s = ft_itoa(line->exit_status);
	if (!exit_s)
		return (ft_free_secure(bloc));
	len = (int)(ft_strlen2(bloc)) - 2 + ft_strlen2(exit_s);
	cpy = malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (free(bloc), free(exit_s), NULL);
	ft_strlcpy(cpy, bloc, i + 1);
	len = 0;
	while (exit_s[len])
		cpy[i++] = exit_s[len++];
	while (bloc[tmp])
		cpy[i++] = bloc[tmp++];
	cpy[i] = '\0';
	free(bloc);
	free(exit_s);
	return (cpy);
}
