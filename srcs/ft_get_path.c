/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:20:18 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/12 20:14:20 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static size_t	ft_countstr(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (s && *s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static size_t	ft_findsize(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (s[size] != c && s[size])
		size++;
	return (size);
}

char	**ft_split_path(char const *s, char c)
{
	size_t	n_str;
	size_t	i;
	char	**split;

	n_str = ft_countstr(s, c);
	split = (char **)malloc((n_str + 1) * sizeof(char *));
	if (!split || !s)
		return (NULL);
	i = 0;
	while (*s && i < n_str)
	{
		while (*s == c)
			s++;
		split[i] = ft_substr(s, 0, ft_findsize(s, c) + 1);
		if (!split[i])
		{
			ft_freesplit(split);
			return (NULL);
		}
		split[i][ft_findsize(s, c)] = '/';
		i++;
		s += ft_findsize(s, c);
	}
	split[i] = NULL;
	return (split);
}

char	*ft_get_pathcmd(char **paths, char *cmd_name)
{
	char	*buffer;
	int		j;

	j = 0;
	while (paths[j])
	{
		buffer = ft_strjoin(paths[j], cmd_name);
		if (!buffer)
		{
			ft_error("Malloc failed in ft_get_pathcmd for cmd : ", cmd_name);
			free(cmd_name);
			return (NULL);
		}
		if (!access(buffer, F_OK))
		{
			free(cmd_name);
			return (buffer);
		}
		free(buffer);
		j++;
	}
	ft_error("Command not found : ", cmd_name);
	free(cmd_name);
	return (NULL);
}

void	ft_get_path(char *pathvar, t_pipex *cmd_line)
{
	char	**paths;
	int		i;

	while (*pathvar != '/')
		pathvar++;
	paths = ft_split_path(pathvar, ':');
	if (!paths)
	{
		ft_error("Mailoc from ft_split_path failed", NULL);
		ft_freesplit(paths);
		ft_clean_exit(cmd_line, EXIT_FAILURE);
	}
	i = 0;
	while (i < cmd_line->n_cmd)
	{
		cmd_line->cmds[i][0] = ft_get_pathcmd(paths, cmd_line->cmds[i][0]);
		i++;
	}
	ft_freesplit(paths);
}
