/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:29:46 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/29 14:12:07 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <termcap.h>

void	term_init_setting(struct termios *old, int *status)
{
	struct termios	t;

	if (!isatty(0))
		return ;
	if (tcgetattr(0, &t) == -1)
		return ((void) perror("Error "));
	*old = t;
	if (t.c_lflag & ECHOCTL)
	{
		t.c_lflag &= ~ECHOCTL;
		if (tcsetattr(0, TCSANOW, &t) == -1)
			perror("Error ");
		else
			*status = 1;
	}
}

void	term_reset(struct termios *old, int *status)
{
	if (!isatty(0) || *status == 0)
		return ;
	if (tcsetattr(0, TCSANOW, old) == -1)
		perror("Error ");
}
