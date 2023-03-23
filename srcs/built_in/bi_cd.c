/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:27:20 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/23 16:47:46 by tlegrand         ###   ########.fr       */
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

static void	ft_update_pwd(t_var_env *lst_env)
{
	char		*oldpwd;
	char		*cwd;
	t_var_env	*tmp;

	oldpwd = get_value(lst_env, "PWD");
	if (ft_var_env_search(lst_env, "OLDPWD"))
		change_value(lst_env, oldpwd, "OLDPWD");
	else
	{
		tmp = ft_new_env("OLDPWD", oldpwd);
		if (!tmp)
			perror("Error ");
		else
			ft_envadd_back(&lst_env, tmp);
	}
	cwd = getcwd(NULL, 0);
	change_value(lst_env, cwd, "PWD");
	free(cwd);
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
			return (perror("Error HOME not set "), EXIT_FAILURE);
		ft_update_pwd(line->lst_env);
		return (EXIT_SUCCESS);
	}
	if (chdir(line->cmd->arg[1]) == -1)
		return (perror("Error "), EXIT_FAILURE);
	ft_update_pwd(line->lst_env);
	return (EXIT_SUCCESS);
}
