/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:06:26 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/28 13:38:22 by lboudjem         ###   ########.fr       */
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

/*			Parsing functiuns				*/
int			ft_parse_line(char *str, int i, int start, t_line *line);
int			ft_bloc_empty(char *bloc);
int			ft_bloc_separate(char **str, int *i, int *start, char **bloc);
int			ft_bloc_fill_list(char *bloc, t_list *io, t_line *line, int *error);
int			ft_bloc_nb_backslash(char *bloc);
void		ft_bloc_cmd(char *arg, t_line *line, t_list	*io);
void		ft_bloc_init(t_list **io, int *error, char **bloc);
void		ft_bloc_format(char **bloc, t_list **io, int *error, t_line *line);
char		*ft_bloc_creat(char *str, int *i, int *start, char *bloc);
char		*ft_bloc_clear_backslash(char *bloc);
char		*ft_bloc_protect_backslash(char *bloc);

/*			Parsing quotes					*/
int			ft_quotes_handle(char *str, int i, int quote, int *error);
int			ft_quotes_get_nb(char *bloc, int i, int nb);
int			ft_quotes_error(char *str, int *i, int *error);
char		*ft_quotes_delete(char *bloc, int i, int j);

/*			Parsing expansion				*/
void		ft_exp_skip_quote(char **bloc, int *i, t_line *line);
char		*ft_exp_get_value(char *bloc, t_line *line, int *len, int i);
char		*ft_exp_replace_value(char *bloc, t_line *line, int len, int i);
char		*ft_exp_replace_exit_status(char *bloc, int i, t_line *line);
char		*ft_exp_handle(char *bloc, t_line *line, int i);
char		*ft_exp_handle_heredoc(char *bloc, t_line *line);

/*			Parsing redirection				*/
int			ft_redirection_type(char *bloc, int *type, int *i);
int			ft_redirection_size(char *bloc, int i, int len);
int			ft_redirection_hd(int *type, t_line *line, char **arg);
void		ft_redirection_skip_quotes(char **bloc, int *i);
void		ft_redirection_init(int *i, int *type, char **arg, t_list **io);
char		*ft_redirection_arg(char *bloc, int i);
char		*ft_redirection_clear(char *bloc, int i);
t_list		*ft_redirection_handle(char **bloc, int *err, t_line *line, int i);

/*			Parsing export					*/
int			ft_export_nb_quotes(char *bloc);
char		*ft_export_protect_quotes(char *bloc);

/*			Parsing utils*/
char		**ft_split_bis(char const *s, char c);

/* 			Get path functiuns				*/
int			ft_path_splitlen(char **split);
int			ft_path_get(char *pathvar, char	**head);

char		*ft_here_doc_mode(char **delimiter);

/*			struct var_env functions			*/
void		ft_var_env_init(t_var_env *lst);
void		ft_env_add_front(t_var_env **lst, t_var_env *new);
void		ft_env_add_back(t_var_env **lst, t_var_env *new);
void		ft_env_free(t_var_env *lst);
void		ft_env_remove(t_var_env **head, t_var_env *todel);
void		ft_env_clear(t_var_env **lst);
void		ft_env_change_value(t_var_env *lst, char *value, char *name);
void		ft_env_fill_lst(t_line *line, int i);
void		ft_env_init(t_var_env **lst, char **env);
void		ft_env_update_shlvl(t_var_env *lst);
char		*ft_env_get_value(t_var_env *lst, char *name);
char		**ft_env_lst_to_tab(t_var_env *lst);
t_var_env	*ft_env_new(char *name, char *value);
t_var_env	*ft_env_last(t_var_env *lst);
t_var_env	*ft_env_search(t_var_env *lst, char *name);

/*			exe functions						*/
int			bi_cd(t_line *line);
int			bi_clear(t_line *line);
int			bi_echo(t_line *line);
int			bi_env(t_line *line);
int			bi_exit(t_line *line);
int			bi_export(t_line *line);
int			bi_loulou(t_line *line);
int			bi_titi(t_line *line);
int			bi_pwd(t_line *line);
int			bi_type(t_line	*line);
int			bi_unset(t_line *line);
void		exe_envtab_update(char ***env, t_var_env *lst);

void		exe_master(t_line *line);
void		exe_restore_std(t_list *io, int std_fd[2]);
void		exe_init_here_pipe(int here_pipe[2]);
void		dup_pipe(int pipe_in[2], int pipe_out[2]);
int			dup_selector(t_list *io, int here_pipe[2], t_line *line);

void		exe_error_404(t_line *line, char *cmd);

/*			utils general	*/
int			ft_is_bi(char *arg);
void		ft_perror_exit(t_line *line, int exit_status, char *errstr);
void		ft_clean_exit(t_line *line, int exit_code);
char		*ft_get_input(t_line *line);

/*			signals functions 		*/
void		sig_init(void (*handler)(int sig));
void		sig_handler_shell(int sig);
void		sig_handler_child(int sig);
void		sig_handler_loulou(int sig);

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
void		s_redirect_del(void *addr);
int			s_redirect_add_list(t_list	**start, int type, char *arg);
int			*s_redirect_acces_type(t_redirect *io);
char		*s_redirect_acces_arg(t_redirect *io);
t_redirect	*s_redirect_new(int type, char *arg);
t_list		*s_redirect_search_type(t_list *lst, int ref);

/*			struct cmd functions			*/
void		s_cmd_init(t_cmd *cmd);
void		s_cmd_del(t_cmd *cmd);
void		s_cmd_clear_lst(t_cmd	**cmd);
void		s_cmd_add_back(t_cmd **start, t_cmd *new);
t_cmd		*s_cmd_new(char **arg, t_list *io);
t_cmd		*s_cmd_new_alloc(char **arg, t_list *io);
t_cmd		*s_cmd_last(t_cmd *cmd);
t_cmd		*s_cmd_first(t_cmd *cmd);

/*			prompt function				*/
char		*prompt_git(void);
char		*prompt_pwd(char *pwd, char *user);
char		*ft_get_a_nice_prompt(t_var_env *lst_env, int exit_status);

/*			debug functions					*/
void		debug_print_cmd_arg(char **arg);
void		debug_print_env(t_var_env	*lst);
void		debug_term_status(void);

/*			color functions		*/
int			ft_colorprint(char *str, char **color_table);

#endif
