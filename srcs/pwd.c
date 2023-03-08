/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:10:16 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/08 13:37:32 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		perror("Error ");
		exit(EXIT_FAILURE);
	}
	if (printf("%s\n", pwd) < 0)
	{
		perror("Error ");
		exit(EXIT_FAILURE);
	}
	free(pwd);
	exit(EXIT_SUCCESS);
}
