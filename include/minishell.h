/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:06:26 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/09 14:59:19 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h> 
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "exec_struct.h"

/*      get path functiuns      */
int		ft_splitlen(char **split);
char	**ft_split_path(char const *s);
char	*ft_get_pathcmd(char **paths, char *cmd_name);
void	ft_get_path(char *pathvar, t_cmd *cmd);

/*             utils            */

//int bi_env(t_line *line)

#endif 