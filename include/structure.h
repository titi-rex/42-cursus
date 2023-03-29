/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:46:27 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/29 13:22:04 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H
# include "../libft/libft.h"

/*	structure for environment variables
*/
typedef struct s_var_env
{
	char				*name;
	char				*value;
	struct s_var_env	*next;
	struct s_var_env	*previous;
}	t_var_env;

/*	structure storing one redirection and point to the next
	type	: 0 == <, 1 == >, 2 == <<, 3 == >>
	arg		: filename or delimiter
*/
typedef struct s_redirect
{
	int					type;
	char				*arg;
}	t_redirect;

/*	structure for one command to execute 
	cmd		: cmd path, flags and arg
	io		: all redirection stored in list
*/
typedef struct s_cmd
{
	char			**arg;
	t_list			*io;
	struct s_cmd	*next;
	struct s_cmd	*previous;
}	t_cmd;

/*	structure holding the whole command line,
*	reset after execution
*/
typedef struct s_line
{
	t_cmd			*cmd;
	char			**env;
	int				pipe[2][2];
	int				fd_std[2];
	int				n_cmds;
	int				exit_status;
	t_var_env		*lst_env;
	struct termios	old;
	int				term_status;
}	t_line;

#endif
