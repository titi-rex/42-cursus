/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:43:01 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/22 20:23:34 by tlegrand         ###   ########.fr       */
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

void	ft_clean_exit(t_line *line, int exit_code)
{
	rl_clear_history();
	s_line_clear(line);
	exit(exit_code);
}

void	ft_var_env_update_shlvl(t_var_env *lst)
{
	t_var_env	*tmp;
	char		*buff;
	int			lvl;

	tmp = ft_var_env_search(lst, "SHLVL");
	if (!tmp)
		return ;
	lvl = ft_atoi(tmp->value);
	lvl += 1;
	buff = ft_itoa(lvl);
	if (!buff)
		return ((void) ft_perror_return_int(NULL));
	change_value(lst, buff, "SHLVL");
	free(buff);
}

void	ft_print_cmd_arg(char **arg)
{
	int	i;

	if (!arg)
		return ((void)ft_putstr_fd("arg NULL\n", 2));
	i = -1;
	while (arg[++i])
		printf("arg[%d] = :%s:\n", i, arg[i]);
	printf("arg[%d] = :%s:\n", i, arg[i]);
}
