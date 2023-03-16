/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisa <louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/15 23:20:13 by louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// 5> test$ segfault

char	*ft_redirection_arg(char *bloc, int i)
{
	int		len;
	int		tmp;
	char	*arg;

	len = 0;
	while (bloc[i] == ' ' || bloc[i] == '\t' || bloc[i] == '\n' \
			|| bloc[i] == '>' || bloc[i] == '<')
		i++;
	tmp = i;
	while (bloc[i] != ' ' && bloc[i] != '\t' && bloc[i] != '\n' \
			&& bloc[i] != '\0' && bloc[i] != '>' && bloc[i] != '<')
	{
		len++;
		i++;
	}
	arg = ft_substr(bloc, tmp, len);
	return (arg);
}

int	ft_redirection_type_fd(char *bloc, int *type, int *i)
{
	if (bloc[*i] == '<')
	{
		*type = 0;
		return (1);
	}
	if (bloc[*i] == '>')
	{
		*type = 1;
		return (1);
	}
	if (ft_strncmp(&bloc[*i], "<<", 2) == 0)
	{
		*type = 2;
		(*i)++;
		return (1);
	}
	if (ft_strncmp(&bloc[*i], ">>", 2) == 0)
	{
		*type = 3;
		(*i)++;
		return (1);
	}
	return (0);
}

// retirer le fd
t_list	*ft_handle_redirection(char *bloc)
{
	int			i;
	int			type;
	int			fd;
	char		*arg;
	t_list		*io;

	i = 0;
	type = -1;
	fd = 0;
	io = NULL;
	arg = NULL;
	while (bloc[i])
	{
		if (ft_redirection_type_fd(bloc, &type, &i) == 1)
		{
			arg = ft_redirection_arg(bloc, i);
			ft_redirect_add_list(&io, type, fd, arg);
			printf("arg.lst = %s\n", ft_redirect_acces_arg(io->content));
			free(arg);
			i++;
		}
		i++;
	}
	return (io);
}

void	ft_list_cmd(char *cmd, t_line *line, t_list	*io)
{
	t_cmd	*cmds;
	char	**split;

	cmds = NULL;
	split = ft_split(cmd, ' ');
	cmds = ft_cmd_new_alloc(split, io);
	(void)line;
	(void)cmds;
}

void	ft_browse_line(char *str, int i, int start, t_line *line)
{
	char	*bloc;
	char	**cmd;
	t_list	*io;
	
	io = NULL;
	bloc = NULL;
	while (str[i])
	{
		ft_quotes(str, &i);
		if (str[i] == '|')
		{
			bloc = ft_creat_bloc(str, &i, &start, bloc);
			ft_handle_expansion(&bloc, line);
			io = ft_handle_redirection(bloc);
			printf("bloc = %s\n", bloc);
			ft_list_cmd(bloc, line, io);
			free(bloc);
		}
		if (str[i] == '\0' || str[i + 1] == '\0')
		{
			bloc = ft_substr(str, start, (i + 1) - start);
			ft_handle_expansion(&bloc, line);
			ft_handle_redirection(bloc);
			printf("bloc = %s\n", bloc);
			free(bloc);
		}
		i++;
	}
	(void)cmd;
}
