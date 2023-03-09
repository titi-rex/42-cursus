/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:20:28 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/09 13:36:12 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_get_pathcmd(char **paths, char *cmd_name, int *err)
{
	char	*buffer;
	int		j;

	j = 0;
	while (cmd_name && paths[j])
	{
		buffer = ft_strjoin(paths[j], cmd_name);
		if (!buffer)
		{
			ft_error(cmd_name, err);
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
	ft_error(cmd_name, err);
	free(cmd_name);
	return (NULL);
}

void	ft_get_path(char *pathvar, t_pipex *cmd_l, int *err)
{
	char	**paths;
	int		i;

	if (!pathvar)
		return ;
	while (*pathvar != '/')
		pathvar++;
	paths = ft_split_path(pathvar);
	if (!paths)
	{
		ft_error("ft_split_path ", err);
		ft_free2d((void **) paths, 0);
		ft_clean_exit(cmd_l, cmd_l->err);
	}
	i = 0;
	while (i < cmd_l->n_cmd)
	{
		if (cmd_l->cmds[i][0] == NULL)
			ft_error("(null) ", err);
		else if (cmd_l->cmds[i][0] && access(cmd_l->cmds[i][0], X_OK) && \
			cmd_l->cmds[i][0][0] != '.' && cmd_l->cmds[i][0][0] != '/')
			cmd_l->cmds[i][0] = ft_get_pathcmd(paths, cmd_l->cmds[i][0], err);
		i++;
	}
	ft_freesplit(paths);
}
