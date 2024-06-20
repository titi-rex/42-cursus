/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:10:12 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/30 09:25:59 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	bi_atoi_256(const char *str)
{
	long int	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
		res %= 256;
	}
	return ((int) sign * res);
}

int	bi_exit_is_number(char *str)
{
	if (*str != '-' && *str != '+' && !ft_isdigit(*str))
		return (1);
	str++;
	if (ft_str_isdigit(str))
		return (1);
	return (0);
}

int	bi_exit(t_line *line)
{
	unsigned char	exit_code;

	if (line->cmd->arg[1] && (bi_exit_is_number(line->cmd->arg[1]) || \
		ft_strlen(line->cmd->arg[1]) > 19))
	{
		ft_putstr_fd("exit : ", 2);
		ft_putstr_fd(line->cmd->arg[1], 2);
		ft_putendl_fd(" : numeric arguent needed", 2);
		exit_code = 2;
	}
	else if (line->cmd->arg[1] && line->cmd->arg[2])
	{
		ft_putendl_fd("exit : too much argument", 2);
		return (2);
	}
	else if (line->cmd->arg && line->cmd->arg[1])
		exit_code = bi_atoi_256(line->cmd->arg[1]);
	else
		exit_code = line->exit_status;
	ft_putendl_fd("exit", 1);
	term_reset(&line->old, &line->term_status);
	ft_clean_exit(line, exit_code);
	return (EXIT_FAILURE);
}
