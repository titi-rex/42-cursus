/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:21:30 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/25 16:31:51 by tlegrand         ###   ########.fr       */
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

void	ft_error(char *errstr, char **cmd);
void	ft_cmd_check(char **cmd);

char	**ft_cmd_search(char *cmd, char *pathvar);
char	**ft_cmd_format(char *cmd, char *path);
void	ft_cmd_exec(int fdin, int fdout, char **cmd);

#endif