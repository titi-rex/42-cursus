/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:46:27 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/06 22:45:12 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*	structure storing one redirection and point to the next
	type	: 0 == <, 1 == >, 2 == <<, 3 == >>
	arg		: filename or delimiter
*/
typedef struct s_redirect
{
	int			type;
	char		*arg;
	t_redirect	*next;
}	t_redirect;

/*	structure for one command to execute 
	cmd		: cmd path, flags and arg
	io		: all redirection stored in list
*/
typedef struct s_cmd
{
	char		**cmd;
	t_redirect	*io;
	t_cmd		*next;
	t_cmd		*previous;
}	t_cmd;

#endif