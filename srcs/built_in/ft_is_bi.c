/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_bi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:00:18 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/29 14:00:47 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_bi(char *arg)
{
	if (!arg)
		return (0);
	if (!ft_strncmp(arg, "cd", 3))
		return (1);
	else if (!ft_strncmp(arg, "echo", 5))
		return (1);
	else if (!ft_strncmp(arg, "clear", 6))
		return (1);
	else if (!ft_strncmp(arg, "env", 4))
		return (1);
	else if (!ft_strncmp(arg, "exit", 5))
		return (1);
	else if (!ft_strncmp(arg, "loulou", 7))
		return (1);
	else if (!ft_strncmp(arg, "export", 7))
		return (1);
	else if (!ft_strncmp(arg, "pwd", 4))
		return (1);
	else if (!ft_strncmp(arg, "type", 5))
		return (1);
	else if (!ft_strncmp(arg, "titi", 5))
		return (1);
	else if (!ft_strncmp(arg, "unset", 6))
		return (1);
	return (0);
}
