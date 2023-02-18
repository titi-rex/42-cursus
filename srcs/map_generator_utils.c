/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:45:31 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/18 16:52:37 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <fcntl.h>

void	ft_putstr_exit(char *strerr, int exit_code)
{
	if (strerr)
		ft_putendl_fd(strerr, 2);
	exit(exit_code);
}

int	ft_man(void)
{
	ft_printf("Map generator need two or three argument : \n");
	ft_printf("Argument shall be the name of your map, height and width\n");
	ft_printf("You can give only height for a square map\n");
	ft_printf("Size argument shall be less than INT_MAX and more than 0\n");
	return (1);
}

void	ft_check_arg(int n, char **arg)
{
	if (n == 4)
	{
		if (ft_atoi(arg[3]) > 0 && ft_atoi(arg[2]) > 0)
			return ;
	}
	if (ft_atoi(arg[2]) > 0)
		return ;
	ft_printf("Argument shall be less than INT_MAX and more than 0\n");
	exit(1);
}

int	ft_is_name_ber(char *pathname)
{
	int	i;

	i = 0;
	while (pathname[i])
	{
		if (!ft_strncmp(&pathname[i], ".ber", 5))
			return (0);
		i++;
	}
	return (1);
}
