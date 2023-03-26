/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:27:20 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/26 14:13:17 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	bi_cd_count_arg(char **arg)
{
	int	n;

	n = 0;
	while (arg[n])
		n++;
	return (n);
}

static void	bi_cd_update_pwd(t_var_env *lst_env)
{
	char		*oldpwd;
	char		*cwd;
	t_var_env	*tmp;

	oldpwd = ft_env_get_value(lst_env, "PWD");
	if (ft_env_search(lst_env, "OLDPWD"))
		ft_env_change_value(lst_env, oldpwd, "OLDPWD");
	else
	{
		tmp = ft_env_new("OLDPWD", oldpwd);
		if (!tmp)
			perror("Error ");
		else
			ft_env_add_back(&lst_env, tmp);
	}
	cwd = getcwd(NULL, 0);
	ft_env_change_value(lst_env, cwd, "PWD");
	free(cwd);
}

int	bi_cd(t_line *line)
{
	char	*home;

	if (bi_cd_count_arg(line->cmd->arg) > 2)
	{
		ft_putstr_fd("Error, too much arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (!line->cmd->arg[1])
	{
		home = ft_env_get_value(line->lst_env, "HOME");
		if (chdir(home) == -1)
			return (perror("Error HOME not set "), EXIT_FAILURE);
		bi_cd_update_pwd(line->lst_env);
		return (EXIT_SUCCESS);
	}
	if (line->cmd->arg[1][0] == '\0')
		return (EXIT_SUCCESS);
	if (chdir(line->cmd->arg[1]) == -1)
		return (perror("Error "), EXIT_FAILURE);
	bi_cd_update_pwd(line->lst_env);
	return (EXIT_SUCCESS);
}
