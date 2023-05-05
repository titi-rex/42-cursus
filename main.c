/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:49:04 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/05 13:38:25 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf(":%.d:\n", 0);
	printf(":%.d:\n", 0);
}

/*
double signe ! -- ou 0b0b
preci 0 with str
bug with %flaggs%%d


- [OUTPUT] ft_printf("%-%%35p" ,(void*)6242906840831513273lu)
   expected: "%                 0x56a342b2059e52b9"
   actual:   "%%35p"

*/