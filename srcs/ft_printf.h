/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:40:41 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/03 21:24:31 by tlegrand         ###   ########.fr       */
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

int		ft_printf(const char *str, ...);

int		flush_buffer(t_print_buffer *p);
int		write_buffer(t_print_buffer *p, char c);

int		padding(t_print_buffer *p, char c, int size);
int		pad_adjust_right(t_print_buffer *p, int size, int sign, int flags[4]);
int		pad_adjust_left(t_print_buffer *p, int size, int flags[4]);

int		get_flags(const char *str, int flags[4]);

int		is_flag(char c);
int		is_specifier(char c);
int		ft_isdigit(int c);
int		ft_max(int a, int b);
int		ft_abs(int a);

int		get_sign(int flag[4], int d);
int		get_base(int flag);

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);

int		get_str(t_print_buffer *p, char *str, int flags[4]);
int		get_uint(t_print_buffer *p, unsigned int number, int size, int flags[4]);
int		get_int(t_print_buffer *p, int number, int size, int flags[4]);

int		conversion_int(t_print_buffer *p, va_list ap, int flags[4]);
int		conversion_uint(t_print_buffer *p, va_list ap, int flags[4]);

int		ft_numlen(long long int num, int base);
int		ft_power_recursive(int nb, int power);

void	print_flags(int flags[4]);
size_t	ft_strlen2(const char *s);

#endif