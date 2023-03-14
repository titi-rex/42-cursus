/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:06:26 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/14 20:23:12 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h> 
# include <string.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "exec_struct.h"
# define READING 301
# define EXECUTION 327
# define MINISHELL 337

/*     			 get path functiuns   		   */
int			ft_splitlen(char **split);
char		**ft_split_path(char const *s);
char		*ft_get_pathcmd(char **paths, char *cmd_name);
void		ft_get_path(char *pathvar, t_cmd *cmd);

char		*ft_here_doc_mode(char *delimiter);

/*			struct var_env functions			*/
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
int			bi_exit(t_line *line);
int			bi_export(t_line *line);
int			bi_pwd(t_line *line);
int			bi_unset(t_line *line);

int			ft_is_this_a_minishell(t_line *line);
void		ft_exe_master(t_line *line);

int			ft_dup_redirect(t_list *io, int here_pipe[2], t_line *line);
void		ft_dup_pipe(int pipe_in[2], int pipe_out[2]);

/*			utils general	*/
int			ft_perror_return_int(char *errstr);
char		*ft_perror_return_null(char *errstr);
int			ft_error_return(char *errstr);
int			ft_is_bi(char **arg);
void		ft_clean_exit(t_line *line, int exit_code);

/*			signals functions 		*/
void		ft_sig_init(void (*handler)(int sig));

void		ft_sig_handler_shell(int sig);
void		ft_sig_handler_child(int sig);

/*			terminal gestion functions		*/
void		term_init_setting(struct termios *old);
void		term_reset(struct termios *old);
void		term_init_termcap(char *data);
void		term_clear(void);

/*			struct line functions			*/
void		s_line_init(t_line *line);
void		s_line_reset(t_line *line);
void		s_line_clear(t_line *line);

/*			struct redirect functions			*/
void		s_redirect_init(t_redirect *io);
int			*ft_redirect_acces_type(t_redirect *io);
int			*ft_redirect_acces_fd(t_redirect *io);
char		*ft_redirect_acces_arg(t_redirect *io);
t_redirect	*ft_redirect_new(int type, int fd, char *arg);
void		ft_redirect_del(void *addr);
t_list		*ft_redirect_search_type(t_list *lst, int ref);

/*			struct cmd functions			*/
void		s_cmd_init(t_cmd *cmd);
t_cmd		*ft_cmd_new(char **arg, t_list *io);
t_cmd		*ft_cmd_new_alloc(char **arg, t_list *io);
void		ft_cmd_del(t_cmd *cmd);
void		ft_cmd_clear_lst(t_cmd	**cmd);
t_cmd		*ft_cmd_last(t_cmd *cmd);
t_cmd		*ft_cmd_first(t_cmd *cmd);
void		ft_cmd_add_back(t_cmd **start, t_cmd *new);
void		ft_clear_cmd(t_cmd **cmd);
void		ft_clear_lst_cmd(t_cmd **cmd);

#endif 