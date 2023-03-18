/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:35:47 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/18 17:23:51 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_get_pathcmd(char **paths, char *cmd_name)
{
	char	*buffer;
	int		j;

	j = 0;
	while (cmd_name && paths[j])
	{
		buffer = ft_strjoin3(paths[j], "/", cmd_name);
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
	free(buffer);
	ft_putstr_fd(cmd_name, 2);
	ft_putendl_fd(" : command not found", 2);
	free(cmd_name);
	return (NULL);
}

int	ft_get_path(char *pathvar, char	**head)
{
	char	**paths;

	if (*head == NULL || ft_is_bi(*head) || !pathvar)
		return (1);
	if (!access(*head, X_OK) || *head[0] == '.' || *head[0] == '/')
		return (0);
	paths = ft_split(pathvar, ':');
	if (!paths)
	{
		perror("Error ");
		return (1);
	}
	*head = ft_get_pathcmd(paths, *head);
	ft_free2d((void **)paths, 0);
	if (!*head)
		return (1);
	return (0);
}
