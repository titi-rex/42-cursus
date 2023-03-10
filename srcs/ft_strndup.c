/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:19:01 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/10 14:43:45 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strndup(char *src, int n)
{
	int		tmp;
	char	*cpy;

	if (!src)
		return (NULL);
	cpy = (char *)malloc((n + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	tmp = 0;
	while (src && src[tmp] && tmp < n)
	{
		cpy[tmp] = src[tmp];
		tmp++;
	}
	cpy[tmp] = '\0';
	return (cpy);
}

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
