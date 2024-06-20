/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:40:41 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/20 21:10:48 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

# define LEFT 0b00000001
# define PRECISION 0b00000010
# define ZERO 0b00000100 
# define BLANK 0b00001000 
# define PLUS 0b00010000 
# define ALTERNATE 0b00100000 

int						ft_printf(const char *str, ...);

int						write_str(char *str, int max);

int						padding(char c, int size);
int						pad_adjust_right(int size, \
	int sign, int flags[4]);
int						pad_adjust_left(int size, \
	int flags[4]);

int						get_flags(const char *str, int flags[4]);
int						get_flags_error(\
	const char **str);

int						is_flag(char c);
int						is_specifier(char c);
int						ft_isdigit(int c);
size_t					ft_strlen2(const char *s);
int						ft_numlen(unsigned long long int num, int base);
int						ft_atoi(const char *str);

long int				ft_abs(long int a);
int						ft_max(int a, int b);
int						ft_min(int a, int b);
unsigned long long int	ft_power_recursive(unsigned long long int nb, \
	int power);

int						extract_number(\
	unsigned long int number, int size, int flags[4]);

int						get_str(va_list ap, int flags[4]);
int						get_int(va_list ap, int flags[4]);
int						get_uint(va_list ap,	int flags[4]);

#endif