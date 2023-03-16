/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:35:47 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/09 14:42:36 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// vefifier que le path a pas deja un / et a un : (dans le split_path)

int	ft_splitlen(char **split)
{
	int	len;

	len = 0;
	while (split[len])
		len++;
	return (len);
}

char	**ft_split_path(char const *s)
{
	char	**split;
	char	*tmp;
	int		len;
	int		i;

	split = ft_split(s, ':');
	if (!split)
		return (NULL);
	len = ft_splitlen(split);
	i = 0;
	while (split[i])
	{
		tmp = ft_strjoin(split[i], "/");
		free(split[i]);
		split[i] = NULL;
		if (!tmp)
		{
			ft_free2d((void **) split, len);
			return (NULL);
		}
		split[i] = tmp;
		i++;
	}
	return (split);
}

char	*ft_get_pathcmd(char **paths, char *cmd_name)
{
	char	*buffer;
	int		j;

	j = 0;
	while (cmd_name && paths[j])
	{
		buffer = ft_strjoin(paths[j], cmd_name);
		if (!buffer)
		{
			perror(cmd_name);
			free(cmd_name);
			return (NULL);
		}
		if (!access(buffer, F_OK))
		{
			free(cmd_name);
			return (buffer);
		}
		j++;
	}
	perror(cmd_name);
	free(buffer);
	buffer = ft_strdup(cmd_name);
	free(cmd_name);
	return (buffer);
}

void	ft_get_path(char *pathvar, t_cmd *cmd)
{
	char	**paths;

	if (!pathvar)
		return ;
	while (*pathvar != '/')
		pathvar++;
	paths = ft_split_path(pathvar);
	if (!paths)
	{
		perror("ft_split_path");
		ft_free2d((void **) paths, 0);
	}
	if (cmd->arg[0] == NULL)
		perror("(null)");
	else if (cmd->arg[0] && access(cmd->arg[0], X_OK) && \
		cmd->arg[0][0] != '.' && cmd->arg[0][0] != '/')
		cmd->arg[0] = ft_get_pathcmd(paths, cmd->arg[0]);
	ft_freesplit(paths);
}
