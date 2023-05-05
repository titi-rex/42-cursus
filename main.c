/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:49:04 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/05 23:06:19 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	a1, a2;

	a1 = 0;
	a2 = 2;
	(void)a1;
	(void)a2;
	ft_printf(":%.01d:", 0);
	printf("\n");
	printf(":%.01d:", 0);
	printf("\n\n");
	ft_printf(":%-15p:\n", NULL);
	printf("\n");
	printf(":%-15p:\n", NULL);
	printf("\n");
}

/*
double signe ! -- ou 0b0b

- [OUTPUT] ft_printf("%-%%35p" ,(void*)6242906840831513273lu)
   expected: "%                 0x56a342b2059e52b9"
   actual:   "%%35p"

*/