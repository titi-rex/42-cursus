/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:18:56 by xle-boul          #+#    #+#             */
/*   Updated: 2023/01/22 18:03:22 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (48 <= str[i] && str[i] <= 57)
		{
			n = n * 10 + str[i] - 48;
			i++;
		}
		else
		{
			write(1, "Le PID est incorrect\n", 21);
			exit(0);
		}
	}
	return (n);
}

int	main(int ac, char *av[])
{
	int				number;
	unsigned char	ascii;

	ascii = 127;
	printf("%c\n", ascii);
	if (ac != 2)
	{
		write(1, "Format: ./a.out <number>\n", 26);
		return (0);
	}
	number = ft_atoi(av[1]);
	write(1, "\"", 1);
	while (number)
	{
		if (32 <= ascii && ascii <= 126)
		{
			if (!(ascii == 34 || ascii == 33 || ascii == 96 || ascii == 59))
			{
				write(1, &ascii, 1);
				number--;
			}
		}
		ascii--;
		if (ascii == 32)
			ascii = 127;
	}
	write(1, "\"", 1);
	return (0);
}