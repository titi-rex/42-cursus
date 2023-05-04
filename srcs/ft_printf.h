/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:40:41 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/04 15:46:45 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include  <stdio.h>

# define LEFT 0b00000001
# define PRECISION 0b00000010
# define ZERO 0b00000100 
# define BLANK 0b00001000 
# define PLUS 0b00010000 
# define ALTERNATE 0b00100000 

# define BUFFER_SIZE 256

typedef struct s_print_buffer
{
	char	buffer[BUFFER_SIZE];
	int		idx;
}	t_print_buffer;

union u_union_int
{
	unsigned int	u_int;
	int				s_int;
};

int							ft_printf(const char *str, ...);

int							flush_buffer(t_print_buffer *p);
int							write_buffer(t_print_buffer *p, char c);
int							write_buffer_str(t_print_buffer *p, char *str, int max);

int							padding(t_print_buffer *p, char c, int size);
int							pad_adjust_right(t_print_buffer *p, int size, \
	int sign, int flags[4]);
int							pad_adjust_left(t_print_buffer *p, int size, \
	int flags[4]);

int							get_flags(const char *str, int flags[4]);
int							get_flags_error(t_print_buffer *p, const char *str);

int							is_flag(char c);
int							is_specifier(char c);
int							ft_isdigit(int c);
size_t						ft_strlen2(const char *s);
int							ft_numlen(unsigned long long int num, int base);
int							ft_atoi(const char *str);

int							ft_abs(int a);
int							ft_max(int a, int b);
int							ft_min(int a, int b);
unsigned long long int		ft_power_recursive(unsigned long long int nb, \
	int power);

int							extract_number(t_print_buffer *p, \
	unsigned long int number, int size, int flags[4]);

int							get_str(t_print_buffer *p, va_list ap, \
	int flags[4]);
int							get_int(t_print_buffer *p, va_list ap, \
	int flags[4]);
int							get_uint(t_print_buffer *p, va_list ap, \
	int flags[4]);

void						debug_print_flags(int flags[4]);

#endif