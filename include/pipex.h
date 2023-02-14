/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:21:30 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/14 15:12:11 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		n_cmd;
	int		fds[2];
	int		pipe[2][2];
	char	**env;
	char	***cmds;
}	t_pipex;

void	ft_get_argv(char **argv, int start, t_pipex *cmd_line);
void	ft_get_path(char *pathvar, t_pipex *cmd_line);
void	ft_get_fd(t_pipex *cmd_line, char **argv, int argc);
void	ft_get_cmdio(t_pipex *cmd_line, int pipefd[2][2]);
void	ft_parsing(char **argv, int argc, int start, t_pipex *cmd_line);

void	ft_cmd_master(t_pipex *cmd_line);

void	ft_free3d(void ***arr, int size3d, int *size2d);
void	ft_free2d(void **arr, int size);
void	ft_close_pipe(int pipefd[2]);
void	ft_close(t_pipex *cmd_line);
void	ft_clean_exit(t_pipex *cmd_line, int exit_code);

void	printsplit(char **split);
void	printpipex(t_pipex *pipex);
void	ft_error(char *errstr, char *cmd_name);

#endif
