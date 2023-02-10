/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:56:31 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/10 16:47:41 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free2d(void **arr, int size)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	if (!size)
	{
		while (arr[++i])
		{
			if (arr[i])
				free(arr[i]);
		}
	}
	else
	{
		while (++i < size)
		{
			if (arr[i])
				free(arr[i]);
		}
	}
	free(arr);
}

void	ft_free3d(void ***arr, int size3d, int *size2d)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	if (!size3d)
	{
		while (arr[++i])
			ft_free2d(arr[i], 0);
	}
	else
	{
		while (++i < size3d)
			ft_free2d(arr[i], size2d[i]);
	}
	free(arr);
}
