/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:01:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/18 23:35:16 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
PWD
exit status 
user			whoami
machine		hostname
TIME_	date +"%T"


int	ft_get_username(char *user)
{
	int		pipefd[2];
	char	buffer[256];

	if (pipe(pipefd) == -1)
		return (1);


}*/

char	*ft_get_a_nice_prompt(t_var_env *lst_env, int exit_status)
{
	char	*prompt;
	char	*user;
	char	*pwd;
	char	*exit;
	char	*git;
	int		i;

	git = NULL;
	i = ft_get_git_status(&git);
	if (i == 1)
		git = ft_strdup("detached");
	user = ft_strdup(get_value(lst_env, "USER"));
	if (!user)
		user = ft_strdup("guest");
	pwd = ft_strdup(get_value(lst_env, "PWD"));
	exit = ft_itoa(exit_status);
	prompt = NULL;


	(void)pwd;
	(void)exit;
	(void)prompt;
	return (prompt);
}
