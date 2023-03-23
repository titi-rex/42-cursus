/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:06:26 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/23 15:48:44 by tlegrand         ###   ########.fr       */
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
# include "structure.h"
# include "mycolors.h"
# define READING 0b0001
# define EXECUTION 0b0010
# define MINISHELL 0b0100
# define INTERRUPT 0b1000

/*          Parsing functiun            */
int			ft_browse_line(char *str, int i, int start, t_line *line);
void		ft_quotes(char *str, int *i, int *error);
char		*ft_creat_bloc(char *str, int *i, int *start, char *bloc);
int			ft_handle_quotes(char *str, int i, int quote, int *error);
char		*ft_delete_quotes(char *bloc, int size, int nb_quotes, char quote);
int			get_nb_quotes(char *bloc, int i);
char		*ft_del_quotes(char *bloc);
char		*ft_get_expansion_value(char *bloc, t_line *line, int *len, int i);
char		*ft_replace_expansion_value(char *bloc, t_line *line, int len, int i);
char		*ft_replace_by_exit_status(char *bloc, int i, t_line *line);
char		*ft_handle_expansion(char *bloc, t_line *line);
char		*ft_redirection_arg(char *bloc, int i);
int			ft_redirection_type_fd(char *bloc, int *type, int *i);
t_list		*ft_handle_redirection(char **bloc, int *error, t_line *line);
char		**ft_split_bis(char const *s, char c);
char		*ft_handle_export(char *bloc);

/*     			get path functiuns   		   */
int			ft_splitlen(char **split);
char		**ft_split_path(char const *s);
char		*ft_get_pathcmd(char **paths, char *cmd_name);
int			ft_get_path(char *pathvar, char	**head);

char		*ft_here_doc_mode(char **delimiter);

/*			struct var_env functions			*/
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
void		fill_lst_env2(t_var_env **lst, char **env);
char		**ft_lstenv_to_tab(t_var_env *lst);
void		fill_lst_env_std(t_var_env **lst);
void		ft_var_env_update_shlvl(t_var_env *lst);

/*			exe functions						*/
int			bi_cd(t_line *line);
int			bi_echo(t_line *line);
int			bi_env(t_line *line);
int			bi_exit(t_line *line);
int			bi_export(t_line *line);
int			bi_pwd(t_line *line);
int			bi_type(t_line	*line);
int			bi_unset(t_line *line);
void		ft_env_update(char ***env, t_var_env *lst);
void		ft_exe_master(t_line *line);

int			ft_dup_redirect(t_list *io, int here_pipe[2], t_line *line);
void		ft_dup_pipe(int pipe_in[2], int pipe_out[2]);
void		ft_restore_std(t_list *io, int std_fd[2]);

/*			utils general	*/
int			ft_perror_return_int(char *errstr);
char		*ft_perror_return_null(char *errstr);
int			ft_error_return(char *errstr);
int			ft_is_bi(char *arg);
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
char		*ft_redirect_acces_arg(t_redirect *io);
t_redirect	*ft_redirect_new(int type, char *arg);
int			ft_redirect_add_list(t_list	**start, int type, char *arg);
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

/*			prompt function				*/
char		*ft_prompt_git(void);
char		*ft_prompt_pwd(char *pwd, char *user);
char		*ft_get_a_nice_prompt(t_var_env *lst_env, int exit_status);

/*			debug functions					*/
void		debug_print_cmd_arg(char **arg);
void		debug_print_env(t_var_env	*lst);
void		debug_term_status(void);

#endif 