/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:53:58 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/22 16:09:23 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdint.h>

/*	encoding/decoding functions	*/
int 	ft_encoding(int dec);
int		ft_decoding(int bin);

/* 	sending functions	*/
void	ft_sender_master(int pid, char *str);

/*	receipt functions	*/
void	ft_sighandler_server(int sig, siginfo_t *sig_info, void *contex);
void	ft_sighandler_client(int sig);

/*	utils functions	*/
void    ft_error(char *errstr);
size_t	ft_intlen(int n);

#endif