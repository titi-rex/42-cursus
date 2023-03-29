/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:36:22 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/29 14:11:45 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exe_envtab_update(char ***env, t_var_env *lst)
{
	char	**buff;

	if (!*env || !lst)
		return ;
	buff = env_lst_to_tab(lst);
	if (!buff)
		return ((void) perror("Error updating envtab "));
	ft_free2d((void **)*env, 0);
	*env = buff;
}

void	exe_restore_std(t_list *io, int std_fd[2])
{
	if (!io)
		return ;
	dup2(std_fd[0], STDIN_FILENO);
	dup2(std_fd[1], STDOUT_FILENO);
}

void	exe_init_here_pipe(int here_pipe[2])
{
	here_pipe[0] = -1;
	here_pipe[1] = -1;
}

void	exe_error_403(t_line *line, char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(" : permission denied", 2);
	line->exit_status = 126;
	ft_clean_exit(line, 126);
}

void	exe_error_404(t_line *line, char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(" : command not found", 2);
	line->exit_status = 127;
	ft_clean_exit(line, 127);
}
