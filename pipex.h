/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:21:30 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/07 14:50:16 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

# ifndef CAT_TMP_FILE
#  define CAT_TMP_FILE "/tmp/tmp_file_cat"
# endif

# ifndef PIPEX_TMP_FILE
#  define PIPEX_TMP_FILE "/tmp/tmp_file_pipex"
# endif

# ifndef HERE_DOC
#  define HERE_DOC "here_doc"
# endif

void	*ft_error(char *errstr, char *cmdname, char *tofree);
int		ft_man(void);
int		ft_pathlen(char *pathvar);

char	**ft_cmd_search(char *cmd, char *pathvar);
char	**ft_cmd_format(char *cmd, char *path);
void	ft_cmd_exec(char *pathname_in, char *pathname_out, char **cmd);

void	ft_cmd_master(char *cmd_raw, char *file1, char *file2, char *pathvar);

int		ft_cat_fd(int fdin, int fdout);
int		ft_man(void);

void	ft_normal_mode(int argc, char **argv, char *pathvar, int start);
void	ft_append_mode(int argc, char **argv, char *pathvar);

int		ft_here_doc(char *end);

#endif