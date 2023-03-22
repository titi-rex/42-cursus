/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:46:53 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/22 16:45:29 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_here_doc(char *end)
{
	char	buff[96];
	char	*here_doc;
	int		n_read;
	int		len;

	n_read = 1;
	here_doc = NULL;
	len = ft_strlen2(end);
	ft_putstr_fd(" prompt $> ", 1);
	while (n_read)
	{
		n_read = read(0, &buff, 95);
		if (n_read == -1)
			break ;
		buff[n_read] = 0;
		if (!ft_strncmp(buff, end, len) && buff[len] == '\n')
			break ;
		if (ft_strrchr(buff, '\n'))
			ft_putstr_fd(" prompt $> ", 1);
		here_doc = ft_self_append(here_doc, buff);
	}
	return (here_doc);
}

char	*ft_here_doc_mode(char **delimiter)
{
	char	*here_doc;

	here_doc = NULL;
	here_doc = ft_here_doc(*delimiter);
	free(*delimiter);
	*delimiter = NULL;
	return (here_doc);
}
