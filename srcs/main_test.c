/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:13 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/09 14:20:43 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **arg)
{
	t_line	line;
	t_cmd	cmd;

	s_init_cmd(&cmd);
	s_init_line(&line);
	line.cmd = &cmd;
	bi_pwd(&line);
	bi_exit(&line);
	(void) arg;
	(void) ac;
	return (0);
}

