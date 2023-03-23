/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:28:28 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/23 21:11:56 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	bi_export_print(t_var_env *lst)
{
	int	err;

	err = EXIT_SUCCESS;
	while (lst)
	{
		if (printf("declare -x %s", lst->name) < 0)
			err = EXIT_FAILURE;
		if (lst->value)
			if (printf("=\"%s\"", lst->value) < 0)
				err = EXIT_FAILURE;
		if (printf("\n") < 0)
			err = EXIT_FAILURE;
		lst = lst->next;
	}
	return (err);
}

static int	bi_export_name_is_valid(char *name)
{
	while (*name)
	{
		if (!ft_isalnum(*name) && *name != '_')
			return (1);
		name++;
	}
	return (0);
}

static char	*bi_export_get_new_value(char **arg)
{
	char	*value;

	if (arg[2] == NULL)
		return (NULL);
	value = ft_strndup(arg[3], ft_strlen2(arg[3]));
	return (value);
}

int	bi_export(t_line *line)
{
	t_var_env	*tmp;
	char		*new_value;

	if (!line->cmd->arg[1])
		return (bi_export_print(line->lst_env));
	if (bi_export_name_is_valid(line->cmd->arg[1]))
		return (ft_putendl_fd("Not a valid identifier ", 2), EXIT_FAILURE);
	tmp = ft_var_env_search(line->lst_env, line->cmd->arg[1]);
	if (tmp)
	{
		free(tmp->value);
		tmp->value = bi_export_get_new_value(line->cmd->arg);
		ft_env_update(&line->env, line->lst_env);
		return (EXIT_SUCCESS);
	}
	new_value = bi_export_get_new_value(line->cmd->arg);
	tmp = ft_new_env(line->cmd->arg[1], new_value);
	if (new_value)
		free(new_value);
	if (!tmp)
		return (perror("Error "), EXIT_FAILURE);
	ft_envadd_back(&line->lst_env, tmp);
	ft_env_update(&line->env, line->lst_env);
	return (EXIT_SUCCESS);
}
