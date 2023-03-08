/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/08 16:13:06 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec_struct.h"

char *prompt (void)
{
	char *invite;

	invite = malloc(4 * sizeof(char));
	invite[0] = '$';
	invite[1] = '>';
	invite[2] = ' ';
	invite[3] = '\0';

	return invite;
}

int main (void)
{
	int end = 0;
	char *s;
	char line[128];

	while (!end)
	{
		s = prompt();

		if (s != NULL)
		{
			ft_putstr_fd(s, 1);
			free (s);
			s = NULL;
		}
	read(1, line, sizeof line);
	end = ft_strncmp(line, "exit\n", 5) == 0;
   }
   return (0);
}