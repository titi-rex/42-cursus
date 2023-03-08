/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:19:09 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/08 16:35:07 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "exec_struct.h"

int		bi_echo(char **arg);
int		bi_pwd(void);
int		bi_cd(char **arg);
void	bi_exit(t_line *line, int exit_status);

#endif