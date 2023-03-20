/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:01:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/20 18:56:19 by tlegrand         ###   ########.fr       */
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
	char	*username;
	char	*user;
	char	*pwd;
	char	*exit;
	char	*git;


	//dprintf(2, "making prompt..\n");
	git = ft_prompt_git();
	user = get_value(lst_env, "USER");
	username = ft_strjoin3(VIOLET, user, END);
	if (!username)
		username = ft_strdup("\033[0;35mguest\033[0m");
	pwd = ft_prompt_pwd(get_value(lst_env, "PWD"), user);
	if (!exit_status)
		exit = ft_strjoin3(GREEN_LIGH BOLD, " (*o*) ", END);
	else
		exit = ft_strjoin3(RED, " (~.~) ", END);
	prompt = ft_multijoin(6, username, " in ", pwd, git, exit, VIOLET"-$> "END);
	if (git)
		free(git);
	free(pwd);
	free(exit);
	free(username);
	//dprintf(2, "prompt finished !\n");
	return (prompt);
}

/*
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