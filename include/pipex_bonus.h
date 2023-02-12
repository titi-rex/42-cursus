/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:16:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/12 20:22:20 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_data
{
	int		n_cmd;
	char	***cmds;
	int		**cmdio;
	int		fds[2];
	int		pipefd[2][2];
	char	**env;
}	t_pipex;

void	ft_get_argv(char **argv, int start, t_pipex *cmd_line);
void	ft_get_path(char *pathvar, t_pipex *cmd_line);
void	ft_get_fd(t_pipex *cmd_line, char **argv, int argc);
void	ft_get_cmdio(t_pipex *cmd_line, int pipefd[2][2]);
void	ft_parsing(char **argv, int argc, int start, t_pipex *cmd_line);

void	ft_cmd_master(t_pipex *cmd_line);

void	ft_free3d(void ***arr, int size3d, int *size2d);
void	ft_free2d(void **arr, int size);
void	ft_close(t_pipex *cmd_line);
void	ft_clean_exit(t_pipex *cmd_line, int exit_code);

void	printsplit(char **split);
void	printpipex(t_pipex *pipex);
void	ft_error(char *errstr, char *cmd_name);

# ifndef HERE_DOC
#  define HERE_DOC "here_doc"
# endif

int		ft_here_doc(char *end, t_pipex *cmd_line);

#endif
