/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:40:41 by tlegrand          #+#    #+#             */
/*   Updated: 2022/11/28 15:23:18 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putadr(void *p);
int		ft_putnbr_base(long long int nbr, char *base);

#endif