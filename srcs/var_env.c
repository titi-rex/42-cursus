/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjem <lboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:58:48 by lboudjem          #+#    #+#             */
/*   Updated: 2023/03/09 16:51:24 by lboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_variables(t_var_env *lst)
{
	lst->name = NULL;
	lst->value = NULL;
	lst->next = NULL;
	lst->previous = NULL;
}

// void	fill_lst_env(t_var_env *lst, t_line *line)
// {
	
// }

//ft_strlen pas le bon