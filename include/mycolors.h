/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mycolors.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:08:43 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/24 15:30:34 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYCOLORS_H
# define MYCOLORS_H

# define BLACK		"\001\033[0;30m\002"
# define RED		"\001\033[0;31m\002"
# define GREEN		"\001\033[0;32m\002"
# define ORANGE		"\001\033[0;33m\002"
# define BLUE		"\001\033[0;34m\002"
# define PURPLE		"\001\033[0;35m\002"
# define CYAN		"\001\033[0;36m\002"
# define GRAY		"\001\033[0;37m\002"
# define END		"\001\033[0m\002"
# define BOLD		"\001\033[1m\002"
# define FAINT		"\001\033[2m\002"
# define ITALIC		"\001\033[3m\002"
# define UNDERLIN	"\001\033[4m\002"
# define BLINK_SLO	"\001\033[5m\002"
# define BLINK_FAS	"\001\033[6m\002"
# define BLINK_OF	"\001\033[25m\002"
# define REV_V		"\001\033[7m\002"
# define CONCEAL	"\001\033[8m\002"
# define CONCEAL_OF	"\001\033[28m\002"
# define CR_OU		"\001\033[9m\002"
# define CR_OUT_OF	"\001\033[29m\002"
# define ERASE		"\001\033[2K\002"
# define RERASE		"\001\r\033[2K\002"
# define CLEAR		"\001\033[2J\002"
# define CURSOR		"\001\033[H\002"
# define SCREEN_RES	"\001\033[?47l\002"

#endif
