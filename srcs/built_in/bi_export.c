/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:28:28 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/25 19:23:46 by tlegrand         ###   ########.fr       */
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
	while (*name && *name != '=')
	{
		if (!ft_isalnum(*name) && *name != '_')
			return (1);
		name++;
	}
	return (0);
}

char	**bi_export_format_arg(char *arg)
{
	char	**format;
	int		i;

	format = ft_calloc(3, sizeof(void *));
	if (!format)
		return (perror("Error "), NULL);
	while (arg[i] && arg[i] != '=')
		i++;
	format[0] = ft_strndup(arg, i);
	if (arg[i])
		format[1] = ft_substr(arg, i + 1, ft_strlen(arg) - i - 1);
	else
		format[1] = NULL;
	if (!format[0] || !format[1])
	{
		perror("Error ");
		ft_free2d((void **)format, 3);
		return (NULL);
	}
	return (format);
}

int	bi_export_change_value(char *arg_no_format, t_var_env *lst_env, char ***env)
{
	t_var_env	*tmp;
	char		**arg;

	arg = bi_export_format_arg(arg_no_format);
	if (!arg)
		return (perror("Error "), EXIT_FAILURE);
	tmp = ft_var_env_search(lst_env, arg[0]);
	if (tmp)
	{
		free(tmp->value);
		tmp->value = arg[1];
	}
	else
		tmp = ft_new_env(arg[0], arg[1]);
	if (!tmp)
		return (perror("Error "), EXIT_FAILURE);
	ft_free2d((void **)arg, 3);
	ft_envadd_back(&lst_env, tmp);
	ft_env_update(env, lst_env);
	return (EXIT_SUCCESS);
}

int	bi_export(t_line *line)
{
	int	err;
	int	i;

	if (!line->cmd->arg[1])
		return (bi_export_print(line->lst_env));
	i = 0;
	err = EXIT_SUCCESS;
	while (line->cmd->arg[i])
	{
		if (bi_export_name_is_valid(line->cmd->arg[i]))
			ft_putendl_fd("Not a valid identifier", 2);
		else
			err = bi_export_change_value(line->cmd->arg[i], \
				line->lst_env, &line->env);
		i++;
	}
	return (err);
}
