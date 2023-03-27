/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:46:53 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/27 12:15:56 by tlegrand         ###   ########.fr       */
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
		if (!ft_strncmp(input, end, len))
			return (free(input), here_doc);
		here_doc = ft_self_append(here_doc, input);
		here_doc = ft_self_append(here_doc, "\n");
		free(input);
		input = NULL;
	}
	write(1, "\n", 1);
	return (here_doc);
}

char	*ft_here_doc_mode(char **delimiter)
{
	char	*here_doc;

	here_doc = NULL;
	here_doc = ft_here_doc(*delimiter);
	free(*delimiter);
	*delimiter = NULL;
	if (!here_doc)
		here_doc = ft_strdup("");
	return (here_doc);
}
