/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:27:20 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/11 15:39:43 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	bi_count_arg(char **arg)
{
	int	n;

	n = 0;
	while (arg[n])
		n++;
	return (n);
}

static void	ft_update_pwd(t_line *line, char *current)
{
	char		*oldpwd;
	t_var_env	*tmp;

	oldpwd = get_value(line->lst_env, "PWD");
	if (ft_var_env_search(line->lst_env, "OLDPWD"))
		change_value(line->lst_env, "OLDPWD", oldpwd);
	else
	{
		tmp = ft_new_env("OLDPWD", oldpwd);
		if (!tmp)
			perror("Error ");
		ft_envadd_back(&line->lst_env, tmp);
	}
	change_value(line->lst_env, "PWD", current);
}

int	bi_cd(t_line *line)
{
	char	*home;

	if (bi_count_arg(line->cmd->arg) > 2)
	{
		ft_putstr_fd("Error, too much arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (!line->cmd->arg[1])
	{
		home = get_value(line->lst_env, "HOME");
		if (chdir(home) == -1)
			return (ft_perror_return(NULL));
		ft_update_pwd(line, home);
		return (EXIT_SUCCESS);
	}
	if (chdir(line->cmd->arg[1]) == -1)
		return (ft_perror_return(NULL));
	ft_update_pwd(line, line->cmd->arg[1]);
	return (EXIT_FAILURE);
}
