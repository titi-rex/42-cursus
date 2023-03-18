/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:36:22 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/18 16:15:51 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	ft_is_bi(char *arg)
{
	if (!arg)
		return (0);
	if (!ft_strncmp(arg, "cd", 3))
		return (1);
	else if (!ft_strncmp(arg, "echo", 5))
		return (1);
	else if (!ft_strncmp(arg, "env", 4))
		return (1);
	else if (!ft_strncmp(arg, "exit", 5))
		return (1);
	else if (!ft_strncmp(arg, "export", 7))
		return (1);
	else if (!ft_strncmp(arg, "pwd", 4))
		return (1);
	else if (!ft_strncmp(arg, "type", 5))
		return (1);
	else if (!ft_strncmp(arg, "unset", 6))
		return (1);
	return (0);
}

void	ft_restore_std(t_list *io, int std_fd[2])
{
	if (!io)
		return ;
	dup2(std_fd[0], STDIN_FILENO);
	dup2(std_fd[1], STDOUT_FILENO);
}
