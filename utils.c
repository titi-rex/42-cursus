/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:35:38 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/06 17:17:34 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_error(char *errstr, char *cmdname, char *tofree)
{
	ft_putstr_fd("Error\n", 2);
	if (cmdname)
	{	
		ft_putstr_fd(errstr, 2);
		ft_putendl_fd(cmdname, 2);
	}
	else
		ft_putendl_fd(errstr, 2);
	if (tofree)
		free(tofree);
	return (NULL);
}

int	ft_man(void)
{
	ft_printf("use me correctly u stupid nerd!\n");
	ft_printf("Like that : ./pipex input_file cmd1 cmd2 output_file\n");
	return (0);
}

int	ft_pathlen(char *pathvar)
{
	int	len;

	len = 0;
	while (pathvar[len] != ':')
		len++;
	return (len);
}
