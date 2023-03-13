/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:10:16 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/13 20:22:25 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*	TODO: use env to get pwd */
int	bi_pwd(t_line *line)
{
	char	*pwd;

	(void)line;
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		perror("Error ");
		return (EXIT_FAILURE);
	}
	if (printf("%s\n", pwd) < 0)
	{
		perror("Error ");
		return (EXIT_FAILURE);
	}
	free(pwd);
	return (EXIT_SUCCESS);
}
