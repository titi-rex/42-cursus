/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:00:24 by tlegrand          #+#    #+#             */
/*   Updated: 2022/11/26 17:29:56 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_rec_putnbr_base(long long int nbr, char *base, int len_base)
{
	int	len;

	len = 0;
	if (nbr > len_base)
		len += ft_rec_putnbr_base(nbr / len_base, base, len_base);
	if (len == -1)
		return (len);
	if (nbr == len_base)
	{
		len += write(1, &base[1], 1);
		if (len == -1)
			return (len);
		len += write(1, &base[0], 1);
		if (len == -1)
			return (len);
	}
	else
		len += write(1, &base[nbr % len_base], 1);
	return (len);
}

int	ft_putnbr_base(long long int nbr, char *base)
{
	int			len_base;
	int			len;

	len_base = ft_check_base(base);
	len = 0;
	if (len_base <= 1)
		return (0);
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		if (len == -1)
			return (len);
		nbr = -nbr;
	}
	len += ft_rec_putnbr_base(nbr, base, len_base);
	return (len);
}
