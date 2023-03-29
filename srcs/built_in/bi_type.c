/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:10:01 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/29 21:02:00 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	bi_type_tl(char *str)
{
	if (!ft_strncmp(str, "loulou", 7))
	{
		printf("loulou is awesome ! <3\n");
		return (1);
	}
	if (!ft_strncmp(str, "titi", 5))
	{
		printf("titi is sleepy... zzz..\n");
		return (1);
	}
	return (0);
}

static int	bi_type_local(char *str)
{
	if (!access(str, X_OK))
		printf("%s is %s\n", str, str);
	else
	{
		printf("type : %s not found\n", str);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	bi_type_search_path(char *pathvar, char **cmd_name)
{
	int		err;
	char	*tmp;

	err = EXIT_SUCCESS;
	tmp = ft_strdup(*cmd_name);
	if (!tmp)
		return (perror("Error "), EXIT_FAILURE);
	if (ft_path_get(pathvar, cmd_name))
	{
		printf("type : %s not found\n", tmp);
		err = EXIT_FAILURE;
	}
	else
		printf("%s is %s\n", tmp, *cmd_name);
	free(tmp);
	return (err);
}

int	bi_type(t_line	*line)
{
	int		i;
	int		err;

	if (line->cmd->arg[1] && line->cmd->arg[1][0] == '-' && \
		line->cmd->arg[1][1] != '\0')
		return (perror("Error : no option available "), 2);
	i = 1;
	err = EXIT_SUCCESS;
	while (line->cmd->arg[i])
	{
		if (bi_type_tl(line->cmd->arg[i]))
			err = EXIT_SUCCESS;
		else if (line->cmd->arg[i][0] == '.' || line->cmd->arg[i][0] == '/')
			err = bi_type_local(line->cmd->arg[i]);
		else if (ft_is_bi(line->cmd->arg[i]))
			printf("%s is minishell built-in\n", line->cmd->arg[i]);
		else
			err = bi_type_search_path(env_get_value(line->lst_env, "PATH"), \
				&line->cmd->arg[i]);
		i++;
	}
	return (err);
}
