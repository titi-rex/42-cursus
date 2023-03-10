/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:06:26 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/10 14:20:02 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h> 
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "exec_struct.h"

/*     			 get path functiuns   		   */
int			ft_splitlen(char **split);
char		**ft_split_path(char const *s);
char		*ft_get_pathcmd(char **paths, char *cmd_name);
void		ft_get_path(char *pathvar, t_cmd *cmd);

/*           	       env      		     	 */
void		print_env(t_var_env	*lst);
void		init_variables(t_var_env *lst);
void		ft_envadd_front(t_var_env **lst, t_var_env *new);
void		ft_envadd_back(t_var_env **lst, t_var_env *new);
void		ft_free_env(t_var_env *lst);
void		ft_envremove(t_var_env *lst);
void		ft_envclear(t_var_env **lst);
void		change_value(t_var_env *lst, char *value, char *name);
char		*get_value(t_var_env *lst, char *name);
t_var_env	*ft_new_env(char *name, char *value);
t_var_env	*ft_envlast(t_var_env *lst);
void		fill_lst_env(t_line *line, int i);

/*				a remettre dans la libft			*/
char		*ft_strndup(char *src, int n);

//int bi_env(t_line *line)

#endif 