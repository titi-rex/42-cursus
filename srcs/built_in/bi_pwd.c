/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:10:16 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/27 16:56:03 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bi_pwd(t_line *line)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		perror("Error gtting cwd in pwd ");
		return (EXIT_FAILURE);
	}
	if (printf("%s\n", pwd) < 0)
	{
		perror("Error printf ");
		return (EXIT_FAILURE);
	}
	free(pwd);
	return (EXIT_SUCCESS);
	(void)line;
}
