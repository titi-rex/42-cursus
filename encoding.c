/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:18:05 by tlegrand          #+#    #+#             */
/*   Updated: 2023/01/21 23:41:59 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_dectobin(int dec)
{
	int	bin;
	int	div;

	bin = 0;
	div = 128;
	while (div != 0)
	{
		if ((dec / div) != 0)
		{
			dec = dec % div;
			bin = bin * 10 + 1;
		}
		else
			bin *= 10;
		div /= 2;
	}
	return (bin);
}

int	ft_decoding(int bin)
{
	int	dec;
	int	mult;

	dec = 0;
	mult = 128;
	while (mult != 0)
	{
		if (bin % 10 == 1)
			dec += mult; 
		mult /= 2;
		bin /= 10;
	}
	return (dec);
}
