/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:43:01 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/15 14:23:34 by tlegrand         ###   ########.fr       */
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
	rl_clear_history();
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

void	ft_env_update(char ***env, t_var_env *lst)
{
	char	**buff;

	buff = ft_lstenv_to_tab(lst);
	if (!buff)
		return ((void) perror("Error "));
	ft_free2d((void **)*env, 0);
	*env = buff;
}

t_var_env	*fill_lst_env_std(void)
{
	t_var_env	*start;
	t_var_env	*new;
	char		*pwd;

	new = NULL;
	start = new;
	new = ft_new_env("SHLVL", "1");
	ft_envadd_back(&start, new);
	pwd = getcwd(NULL, 0);
	if (!pwd)
		new = ft_new_env("PWD", "");
	else
	{
		new = ft_new_env("PWD", pwd);
		free(pwd);
	}
	ft_envadd_back(&start, new);
	return (start);
}

void	ft_var_env_update_shlvl(t_var_env *lst)
{
	char	*buff;
	int		lvl;

	lvl = ft_atoi(ft_var_env_search(lst, "SHLVL")->value);
	lvl += 1;
	buff = ft_itoa(lvl);
	if (!buff)
		return ((void) ft_perror_return_int(NULL));
	change_value(lst, buff, "SHLVL");
}
