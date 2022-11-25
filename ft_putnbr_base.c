/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:00:24 by tlegrand          #+#    #+#             */
/*   Updated: 2022/11/25 18:23:57 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_rec_putnbr_base(int nbr, char *base, int len)
{
	int	n;

	n = 0;
	if (nbr > len)
		n += ft_rec_putnbr_base(nbr / len, base, len);
	n += write(1, &base[nbr % len], 1);
	return (n);
}

int	ft_check_base(char *base)
{
	int		len;
	int		i;

	len = 0;
	while (base[len])
	{
		i = len + 1;
		if (base[len] == 45 || base[len] == 43 || base[len] <= 32)
			return (1);
		while (base[i] != base[len] && base[i])
			i++;
		if (base[i] != 0)
			return (1);
		len++;
	}
	return (len);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int		len_base;
	int		n;

	len_base = ft_check_base(base);
	n = 0;
	if (len_base <= 1)
		return (0);
	if (nbr < 0)
	{
		n += write(1, "-", 1);
		nbr = -nbr;
	}
	n += ft_rec_putnbr_base(nbr, base, len_base);
	return (n);
}
