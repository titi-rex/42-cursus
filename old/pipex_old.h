/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_old.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:04:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/11 21:04:52 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_OLD_H
# define PIPEX_OLD_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include <string.h>

# ifndef CAT_TMP_FIL
#  define CAT_TMP_FILE "/tmp/tmp_file_cat"
# endif

# ifndef PIPEX_TMP_FILE
#  define PIPEX_TMP_FILE "/tmp/tmp_file_pipex"
# endif

# ifndef HERE_DOC
#  define HERE_DOC "here_doc"
# endif

int		ft_pathlen(char *pathvar);

char	**ft_cmd_search(char *cmd, char *pathvar);
char	**ft_cmd_format(char *cmd, char *path);
void	ft_cmd_exec(char *pathname_in, char *pathname_out, char **cmd);

void	ft_cmd_master(char *cmd_raw, char *file1, char *file2, char *pathvar);

int		ft_cat_fd(int fdin, int fdout);

void	ft_normal_mode(int argc, char **argv, char *pathvar, int start);
void	ft_append_mode(int argc, char **argv, char *pathvar);

#endif