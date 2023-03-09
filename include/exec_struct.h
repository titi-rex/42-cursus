/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:46:27 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/09 21:04:51 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_STRUCT_H
# define EXEC_STRUCT_H

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
	struct s_redirect	*next;
}	t_redirect;

/*	structure for one command to execute 
	arg		: cmd path, flags and arg
	io		: all redirection stored in list
*/
typedef struct s_cmd
{
	char			**arg;
	t_redirect		*io;
	struct s_cmd	*next;
	struct s_cmd	*previous;
}	t_cmd;

/*	structure holding the whole command line, only used in exec part
*/
typedef struct s_line
{
	t_cmd	*cmd;
	int		pipe[2][2];
	int		n_cmds;
	int		exit_status;
	void	*env;
}	t_line;

/*	structure storing fd called by a varname
	varname must be {varname}
	name is either varname or {varname}, up to you 
	int is the fd linked
*/
typedef struct s_varfd
{
	char			*name;
	int				fd;
	struct s_varfd	*next;
}	t_varfd;

#endif