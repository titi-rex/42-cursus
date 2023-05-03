/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:40:41 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/03 16:13:22 by tlegrand         ###   ########.fr       */
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

int	ft_printf(const char *str, ...);

int	ft_flush_buffer(t_print_buffer *p);
int	padding(t_print_buffer *p, char c, int size);
int	get_flags(const char *str, int flags[3]);

int	is_flag(char c);
int	is_specifier(char c);
int	ft_isdigit(int c);
int	ft_max(int a, int b);

int	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);


int	get_char(t_print_buffer *p, char c);
int	get_str(t_print_buffer *p, char *str, int flags[3]);
int	get_uint(t_print_buffer *p, unsigned int number, int base, int flags[3]);
int	get_int(t_print_buffer *p, int number, int size, int flags[3]);

int	ft_numlen(long long int num, int base);
int	ft_power_recursive(int nb, int power);

void	print_flags(int flags[3]);
size_t	ft_strlen2(const char *s);

#endif