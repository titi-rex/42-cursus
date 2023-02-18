/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:18:51 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/18 17:39:45 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_GEN_H
# define MAP_GEN_H
# include "../libft/libft.h"
# include <fcntl.h>

/*	security mode for map creation, use O_TRUNC or O_APPEND	*/
# ifndef DISTRIBUTION
#  define DISTRIBUTION "E00000001CCCP"
# endif

int		ft_man(void);
void	ft_putstr_exit(char *strerr, int exit_code);
void	ft_check_arg(int n, char **arg);
int		ft_is_name_ber(char *pathname);

#endif