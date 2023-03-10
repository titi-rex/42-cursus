/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:19:01 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/10 14:19:17 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strndup(char *src, int n)
{
	int		tmp;
	char	*cpy;

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
