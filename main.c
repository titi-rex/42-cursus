/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:42:16 by tlegrand          #+#    #+#             */
/*   Updated: 2022/11/19 17:01:25 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	int		n;

	n = 53;
	printf("int n = %d\n", n);
	printf("flags : space\t:% dendl\n", n);
	printf("flags : +\t:%+dendl\n", n);
	printf("flags : -\t:%-dendl\n", n);
	printf("flags : 0\t:%0dendl\n", n);
	printf("flags : .\t:%.dendl\n", n);
	printf("flags : #\t:error undefined behavior\n");

	printf("mixed flags : \n");
	printf("flags : space + : space is ignored\n");
	printf("flags : 0 . : 0 is ignored\n");
	printf("flags : 0 - : 0 is ignored\n");

	return (0);
}
