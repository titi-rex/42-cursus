/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:27:20 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/29 21:00:09 by tlegrand         ###   ########.fr       */
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

	oldpwd = env_get_value(lst_env, "PWD");
	if (env_search(lst_env, "OLDPWD"))
		env_change_value(lst_env, oldpwd, "OLDPWD");
	else
	{
		tmp = s_env_new("OLDPWD", oldpwd);
		if (!tmp)
			perror("Error creating OLDPWD");
		else
			s_env_add_back(&lst_env, tmp);
	}
	cwd = getcwd(NULL, 0);
	if (!cwd)
		perror("Error getting cwd in update pwd ");
	env_change_value(lst_env, cwd, "PWD");
	free(cwd);
}

int	bi_cd_chdir_from_env(t_var_env *lst_env, char *target)
{
	char	*tmp;

	tmp = env_get_value(lst_env, target);
	if (!tmp)
	{
		ft_putstr_fd("Error : ", 2);
		ft_putstr_fd(target, 2);
		ft_putstr_fd(" not set\n", 2);
		return (EXIT_FAILURE);
	}
	if (chdir(tmp) == -1)
		return (perror("Error "), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	bi_cd(t_line *line)
{
	if (line->cmd->arg[1] && line->cmd->arg[1][0] == '-' && \
		line->cmd->arg[1][1] != '\0')
		return (perror("Error : no option available "), 2);
	if (bi_cd_count_arg(line->cmd->arg) > 2)
		return (ft_putstr_fd("Error, too much arguments\n", 2), 2);
	if (!line->cmd->arg[1] || !ft_strncmp(line->cmd->arg[1], "~", 2))
	{
		if (bi_cd_chdir_from_env(line->lst_env, "HOME"))
			return (EXIT_FAILURE);
	}
	else if (line->cmd->arg[1][0] == '\0')
		return (EXIT_SUCCESS);
	else if (!ft_strncmp(line->cmd->arg[1], "-", 2))
	{
		if (bi_cd_chdir_from_env(line->lst_env, "OLDPWD"))
			return (EXIT_FAILURE);
	}
	else if (chdir(line->cmd->arg[1]) == -1)
		return (perror("Error "), EXIT_FAILURE);
	bi_cd_update_pwd(line->lst_env);
	return (EXIT_SUCCESS);
}
