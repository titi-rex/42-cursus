/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:16:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/14 19:39:38 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../include/pipex.h"

int		ft_here_doc(char *end, t_pipex *cmd_line);
void	ft_get_fd_doc(t_pipex *cmd_l, char **arg, int argc);
void	ft_parsing_doc(char **argv, int argc, int start, t_pipex *cmd_line);

#endif
