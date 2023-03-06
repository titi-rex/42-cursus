/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:46:27 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/06 22:01:25 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_redirect
{
	int			type;
	char		*arg;
	t_redirect	*next;
}	t_redirect;

typedef struct s_cmd
{
	char		**cmd;
	t_redirect	*io;
	t_cmd		*next;
	t_cmd		*previous;
}	t_cmd;

#endif