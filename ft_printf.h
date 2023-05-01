/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:40:41 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/01 20:10:49 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
#include  <stdio.h>

# define BUFFER_SIZE 256

# define HYPHEN 0b00000001
# define DOT 0b00000010
# define ZERO 0b00000100 
# define BLANK 0b00001000 
# define PLUS 0b00010000 
# define HASH 0b00100000 



int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putadr(void *p);
int		ft_putnbr_base(long long int nbr, char *base);

#endif