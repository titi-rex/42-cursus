/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:35:47 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/27 14:01:37 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_path_getcmd(char **paths, char *cmd_name)
{
	char	*buffer;
	int		j;

	j = 0;
	while (cmd_name && paths[j])
	{
		buffer = ft_strjoin3(paths[j], "/", cmd_name);
		if (!buffer)
			return (perror("Error "), NULL);
		if (!access(buffer, F_OK))
			return (buffer);
		free(buffer);
		j++;
	}
	return (NULL);
}

int	ft_path_get(char *pathvar, char	**head)
{
	char	**paths;
	char	*tmp;

	if (*head == NULL || ft_is_bi(*head))
		return (1);
	if (!ft_strncmp(*head, "/", 2) || !ft_strncmp(*head, ".", 2) \
		|| *head[0] == '\0')
		return (1);
	if (!access(*head, X_OK))
		return (0);
	if (!pathvar)
		return (1);
	paths = ft_split(pathvar, ':');
	if (!paths)
	{
		perror("Error ");
		return (1);
	}
	tmp = ft_path_getcmd(paths, *head);
	ft_free2d((void **)paths, 0);
	if (!tmp)
		return (1);
	free(*head);
	*head = tmp;
	return (0);
}
