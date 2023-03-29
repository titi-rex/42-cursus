/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:28:28 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/29 15:58:49 by tlegrand         ###   ########.fr       */
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
	if (!ft_isalpha(*name) && *name != '_')
		return (1);
	while (*name && *name != '=')
	{
		if (!ft_isalnum(*name) && *name != '_')
			return (1);
		name++;
	}
	return (0);
}

static char	**bi_export_format_arg(char *arg)
{
	char	**format;
	int		i;

	format = ft_calloc(3, sizeof(void *));
	if (!format)
		return (perror("Error "), NULL);
	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	format[0] = ft_strndup(arg, i);
	if (format[0] && !arg[i])
	{
		format[1] = NULL;
		return (format);
	}
	format[1] = ft_substr(arg, i + 1, ft_strlen(arg) - i - 1);
	if (!format[0] || !format[1])
	{
		ft_free2d((void **)format, 3);
		return (perror("Error "), NULL);
	}
	return (format);
}

static int	bi_export_change_value(char *arg_no_format, t_var_env **lst_env)
{
	t_var_env	*tmp;
	char		**arg;

	arg = bi_export_format_arg(arg_no_format);
	if (!arg)
		return (EXIT_FAILURE);
	tmp = env_search(*lst_env, arg[0]);
	if (tmp)
	{
		if (!arg[1])
			return (ft_free2d((void **)arg, 3), EXIT_SUCCESS);
		free(tmp->value);
		tmp->value = ft_strdup(arg[1]);
	}
	else
	{
		tmp = s_env_new(arg[0], arg[1]);
		if (!tmp)
			return (ft_free2d((void **)arg, 3), perror("Error "), EXIT_FAILURE);
		s_env_add_back(lst_env, tmp);
	}
	ft_free2d((void **)arg, 3);
	return (EXIT_SUCCESS);
}

int	bi_export(t_line *line)
{
	int	err;
	int	i;

	if (!line->cmd->arg[1])
		return (bi_export_print(line->lst_env));
	i = 1;
	err = EXIT_SUCCESS;
	while (line->cmd->arg[i])
	{
		if (bi_export_name_is_valid(line->cmd->arg[i]))
		{
			ft_putendl_fd("Not a valid identifier", 2);
			err = 2;
		}
		else
			err = bi_export_change_value(line->cmd->arg[i], &line->lst_env);
		i++;
	}
	exe_envtab_update(&line->env, line->lst_env);
	return (err);
}
