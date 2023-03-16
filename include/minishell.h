/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:06:26 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/16 14:53:18 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h> 
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "exec_struct.h"

/*                  Parsing functiun            */
int			ft_browse_line(char *str, int i, int start, t_line *line);
void		ft_quotes(char *str, int *i);
char		*ft_creat_bloc(char *str, int *i, int *start, char *bloc);
int			ft_handle_quotes(char *str, int i, int quote);
char		*ft_delete_quotes(char *bloc, int size, int nb_quotes);
char		*ft_get_expansion_value(char *bloc, t_line *line, int *len, int i);
char		*ft_replace_expansion_value(char *bloc, t_line *line, int len, int i);
char		*ft_replace_by_exit_status(char *bloc, int i, t_line *line);
char		*ft_handle_expansion(char *bloc, t_line *line);

/*     			 get path functiuns   		   */
int			ft_splitlen(char **split);
char		**ft_split_path(char const *s);
char		*ft_get_pathcmd(char **paths, char *cmd_name);
void		ft_get_path(char *pathvar, t_cmd *cmd);

/*           	       env      		     	 */
int			print_env(t_var_env	*lst);
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
t_var_env	*ft_var_env_search(t_var_env *lst, char *name);
void		fill_lst_env(t_line *line, int i);

/*				exe functions						*/
int			bi_cd(t_line *line);
int			bi_echo(t_line *line);
int			bi_env(t_line *line);
int			bi_env_mod(t_line *line);
int			bi_exit(t_line *line);
int			bi_export(t_line *line);
int			bi_pwd(t_line *line);
int			bi_unset(t_line *line);

void		ft_exe_master(t_line *line);

int			ft_dup_redirect(t_list *io, int here_pipe[2], t_line *line);
void		ft_dup_pipe(int pipe_in[2], int pipe_out[2]);

void		ft_clear_cmd(t_cmd **cmd);
void		ft_clear_lst_cmd(t_cmd **cmd);
void		ft_clear_line(t_line *line);
void		ft_clear_line_exit(t_line *line, int exit_code);

void		s_init_redirect(t_redirect *io);
void		s_init_cmd(t_cmd *cmd);
void		s_init_line(t_line *line);

/*			EXPERIEMENTAL VARFD LST			*/
int			*ft_varfd_acces_fd(t_varfd *varfd);
char		*ft_varfd_acces_varname(t_varfd *varfd);
t_varfd		*ft_varfd_new(char *varname, int fdcount);
void		ft_varfd_del(void *addr);
t_list		*ft_varfd_search(t_list *lst, char *name);
int			ft_varfd_get_value_from_key(t_line *line, char *name);

/*			EXPERIEMENTAL IO LST			*/
int			*ft_redirect_acces_type(t_redirect *io);
char		*ft_redirect_acces_arg(t_redirect *io);
t_redirect	*ft_redirect_new(int type, char *arg);
void		ft_redirect_del(void *addr);
t_list		*ft_redirect_search_type(t_list *lst, int ref);
int			ft_redirect_add_list(t_list	**start, int type, char *arg);

/*			LESS EXPERIEMENTAL CMD LST			*/
t_cmd		*ft_cmd_new(char **arg, t_list *io);
t_cmd		*ft_cmd_new_alloc(char **arg, t_list *io);
void		ft_cmd_del(t_cmd *cmd);
void		ft_cmd_clear_lst(t_cmd	**cmd);
t_cmd		*ft_cmd_last(t_cmd *cmd);
t_cmd		*ft_cmd_first(t_cmd *cmd);
void		ft_cmd_add_back(t_cmd **start, t_cmd *new);

/*			utils general	*/
int			ft_perror_return(char *errstr);
int			ft_error_return(char *errstr);
int			ft_is_bi(char **arg);

/*			signals functions 		*/
void		ft_sig_launch(void);
void		ft_sig_handler_child(int sig, siginfo_t *sig_info, void *context);

#endif 