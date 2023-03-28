/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:43:01 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/28 16:18:08 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_perror_exit(t_line *line, int exit_status, char *errstr)
{
	if (errstr)
		perror(errstr);
	else
		perror("Error ");
	ft_clean_exit(line, exit_status);
}

void	ft_clean_exit(t_line *line, int exit_code)
{
	rl_clear_history();
	s_line_clear(line);
	exit(exit_code);
}

char	*ft_get_input(t_line *line)
{
	char	*prompt;
	char	*input;

	dup2(STDERR_FILENO, STDOUT_FILENO);
	prompt = ft_get_a_nice_prompt(line->lst_env, line->exit_status);
	if (prompt)
	{
		input = readline(prompt);
		free(prompt);
	}
	else
		input = readline("guest@minishell $> ");
	if (input && input[0] != '\0')
		add_history(input);
	else if (!input)
	{
		ft_putendl_fd("exit", 1);
		term_reset(&line->old);
		dup2(line->fd_std[0], STDOUT_FILENO);
		ft_clean_exit(line, line->exit_status);
	}
	dup2(line->fd_std[0], STDOUT_FILENO);
	return (input);
}

void	ft_error(int errnum)
{
	if (errnum == 1)
		ft_printf("Error parsing\n");
	else if (errnum == 2)
		ft_printf("Error malloc\n");
}

void	*ft_free_secure(char *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}
