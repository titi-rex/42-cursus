/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:19:09 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/08 18:35:59 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "exec_struct.h"

int		bi_echo(char **arg);
int		bi_pwd(void);
int		bi_cd(char **arg);
void	bi_exit(t_line *line, int exit_status);
int		ft_is_bi(char *name);
void	ft_bi_selector(t_line *line, int pipe_in[2], int pipe_out[2]);

int		ft_dup_redirect(t_redirect *io, int here_pipe[2]);
void	ft_dup_pipe(int pipe_in[2], int pipe_out[2]);


void	ft_clear_cmd(t_cmd *cmd);
void	ft_clear_lst_cmd(t_cmd *cmd);
void	ft_clear_line(t_line *line);
void	ft_clear_line_exit(t_line *line, int exit_code);


#endif