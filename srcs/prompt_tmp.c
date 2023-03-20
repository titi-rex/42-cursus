/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:01:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/20 19:30:04 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_prompt_username(char *user)
{
	char	*username;

	username = ft_strjoin3(VIOLET, user, END);
	if (!username)
		username = ft_strdup(VIOLET"guest"END);
	return (username);
}

/*	TODO:	ft_prompt_user	*/
/*	TODO:	clean	*/
char	*ft_get_a_nice_prompt(t_var_env *lst_env, int exit_status)
{
	char	*username;
	char	*pwd;
	char	*git;
	char	*prompt;


	git = ft_prompt_git();
	pwd = ft_prompt_pwd(get_value(lst_env, "PWD"), get_value(lst_env, "USER"));
	username = ft_prompt_username(get_value(lst_env, "USER"));

	if (!exit_status)
		prompt = ft_multijoin(5, username, pwd, git, GREEN_L BOLD" (*o*) "END, \
			VIOLET"-$> "END);
	else
		prompt = ft_multijoin(5, username, pwd, git, RED" (~.~) "END, \
			VIOLET"-$> "END);

	if (git)
		free(git);
	free(pwd);
	free(username);
	return (prompt);
}

/*

PWD
exit status 
user			whoami
machine		hostname
TIME_	date +"%T"


reina in pwd on (main) 


>_
$>
}>

exit code :
 (^_^)	(T_T)

 :-)  :-(

	[$]

	(~.~)	(*o*)

	*/