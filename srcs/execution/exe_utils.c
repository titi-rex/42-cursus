/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:36:22 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/15 18:22:47 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	ft_env_update(char ***env, t_var_env *lst)
{
	char	**buff;

	if (!*env || !lst)
		return ;
	buff = ft_lstenv_to_tab(lst);
	if (!buff)
		return ((void) perror("Error "));
	ft_free2d((void **)*env, 0);
	*env = buff;
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
