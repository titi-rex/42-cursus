/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:46:53 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/29 13:01:39 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern sig_atomic_t	g_status;

static char	*ft_here_doc_interrupt(char *here_doc, char **input)
{
	if (*input)
		free(*input);
	write(1, RERASE, sizeof(RERASE));
	return (here_doc);
}

char	*ft_here_doc(char *end)
{
	char	*input;
	char	*here_doc;
	char	*tmp;
	int		len;

	here_doc = NULL;
	len = ft_strlen2(end);
	while (1)
	{
		if (g_status & INTERRUPT)
			return (ft_here_doc_interrupt(here_doc, &input));
		input = readline(" $> ");
		if (!input)
			break ;
		if (!ft_strncmp(input, end, len + 1))
			return (free(input), here_doc);
		tmp = ft_strjoin3(here_doc, input, "\n");
		input = ft_free_secure(input);
		if (!tmp)
			return (perror("Error adding line to here_doc "), here_doc);
		free(here_doc);
		here_doc = tmp;
	}
	write(1, "\n", 1);
	return (here_doc);
}

char	*ft_here_doc_mode(char **delimiter)
{
	char	*here_doc;

	if (!*delimiter)
		return (NULL);
	here_doc = ft_here_doc(*delimiter);
	free(*delimiter);
	*delimiter = NULL;
	return (here_doc);
}
