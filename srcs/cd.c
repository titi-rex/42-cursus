/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:27:20 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/08 14:05:19 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*	TODO: check if cd print pwd after cd at school	*/
/*	TODO: check beaviohor when piped	*/
/*	FIXME: perror display succes when error too much arg	*/
int	cd(char **arg)
{
	if (arg[2])
	{
		perror("Error, too much arguments ");
		return (EXIT_FAILURE);
	}
	if (!chdir(arg[1]))
	{
		if (arg[1][0] != '.' && arg[1][0] != '/' )
			pwd();
		return (EXIT_SUCCESS);
	}
	perror("Error ");
	return (EXIT_FAILURE);
}
