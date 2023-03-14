/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:43:01 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/14 20:24:14 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_perror_return_int(char *errstr)
{
	if (errstr)
		perror(errstr);
	else
		perror("Error ");
	return (EXIT_FAILURE);
}

char	*ft_perror_return_null(char *errstr)
{
	if (errstr)
		perror(errstr);
	else
		perror("Error ");
	return (NULL);
}

int	ft_error_return(char *errstr)
{
	if (errstr)
		ft_putendl_fd(errstr, 2);
	else
		ft_putendl_fd("Error", 2);
	return (EXIT_FAILURE);
}

int	ft_is_bi(char **arg)
{
	if (!arg || !arg[0])
		return (1);
	if (!ft_strncmp(arg[0], "cd", 3))
		return (1);
	else if (!ft_strncmp(arg[0], "echo", 5))
		return (1);
	else if (!ft_strncmp(arg[0], "env", 4))
		return (1);
	else if (!ft_strncmp(arg[0], "exit", 5))
		return (1);
	else if (!ft_strncmp(arg[0], "export", 7))
		return (1);
	else if (!ft_strncmp(arg[0], "pwd", 4))
		return (1);
	else if (!ft_strncmp(arg[0], "unset", 6))
		return (1);
	return (0);
}

void	ft_clean_exit(t_line *line, int exit_code)
{
	term_reset(&line->old);
	s_line_clear(line);
	exit(exit_code);
}

/**
 * @brief look for a valid minishell command in cmd list
 *  line shouldnt be NULL
 */
int	ft_is_this_a_minishell(t_line *line)
{
	t_cmd	*current;

	current = line->cmd;
	while (current)
	{
		if (current->arg)
			if (!access(current->arg[0], X_OK) && !ft_strncmp(current->arg[0] + \
				ft_strlen2(current->arg[0]) - 9, "minishell", 11))
				return (1);
		current = current->next;
	}
	current = line->cmd;
	while (current)
	{
		if (current->arg)
			if (!access(current->arg[0], X_OK) && !ft_strncmp(current->arg[0] + \
				ft_strlen2(current->arg[0]) - 9, "minishell", 11))
				return (1);
		current = current->previous;
	}
	return (0);
}
