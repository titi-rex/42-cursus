/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:19:09 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/08 13:58:59 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "exec_struct.h"

void	echo(char **arg);
void	pwd(void);
int		cd(char **arg);

#endif