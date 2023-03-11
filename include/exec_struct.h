/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:46:27 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/11 12:38:09 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_STRUCT_H
# define EXEC_STRUCT_H

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
	fd		: fd to redirect from/to (defaults : 0 for < and <<, 1 for > and >>)
	arg		: filename or delimiter
*/
typedef struct s_redirect
{
	int					type;
	int					fd;
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

/*	structure holding the whole command line, only used in exec part
*/
typedef struct s_line
{
	t_cmd		*cmd;
	char		**env;
	char		*path;
	int			pipe[2][2];
	int			n_cmds;
	int			exit_status;
	t_var_env	*lst_env;
	t_list		*lst_varfd;
	int			fdcount;
}	t_line;

/*	structure storing fd called by a varname
	varname must be {name} format
	int is the fd linked
*/
typedef struct s_varfd
{
	char			*varname;
	int				fd;
}	t_varfd;

#endif
