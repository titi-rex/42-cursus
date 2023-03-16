/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:07 by louisa            #+#    #+#             */
/*   Updated: 2023/03/16 14:52:08 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// "'echo $SHELL'" ne remplace pas $SHELL alors qu'il devrait

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
	if (!bloc[i])
		return (NULL);
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
t_list	*ft_handle_redirection(char *bloc, int *error)
{
	int			i;
	int			type;
	char		*arg;
	t_list		*io;

	i = 0;
	type = -1;
	io = NULL;
	arg = NULL;
	while (bloc[i])
	{
		if (ft_redirection_type_fd(bloc, &type, &i) == 1)
		{
			arg = ft_redirection_arg(bloc, i);
			if (!arg)
				return (*error = 1, NULL);
			ft_redirect_add_list(&io, type, arg);
			free(arg);
			i++;
		}
		i++;
	}
	return (*error = 0, io);
}

void	ft_list_cmd(char *arg, t_line *line, t_list	*io)
{
	t_cmd	*cmds;
	char	**split;

	cmds = NULL;
	split = ft_split(arg, ' ');
	cmds = ft_cmd_new_alloc(split, io);
	line->cmd = cmds;
	//printf("arg = %s\n", ft_redirect_acces_arg(line->cmd->io->content));
	(void)line;
	(void)cmds;
}

int	ft_browse_line(char *str, int i, int start, t_line *line)
{
	char	*bloc;
	t_list	*io;
	int		error;

	io = NULL;
	bloc = NULL;
	error = 0;
	while (str[i])
	{
		ft_quotes(str, &i);
		if (str[i] == '|')
		{
			bloc = ft_creat_bloc(str, &i, &start, bloc);
			bloc = ft_handle_expansion(bloc, line);
			io = ft_handle_redirection(bloc, &error);
			if (error == 1)
				return (1);
			printf("bloc = %s\n", bloc);
			ft_list_cmd(bloc, line, io);
			free(bloc);
		}
		if (str[i] == '\0' || str[i + 1] == '\0')
		{
			bloc = ft_substr(str, start, (i + 1) - start);
			bloc = ft_handle_expansion(bloc, line);
			io = ft_handle_redirection(bloc, &error);
			if (error == 1)
				return (1);
			printf("bloc = %s\n", bloc);
			ft_list_cmd(bloc, line, io);
			free(bloc);
		}
		i++;
	}
	return (0);
}
