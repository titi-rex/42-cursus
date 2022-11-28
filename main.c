/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:42:16 by tlegrand          #+#    #+#             */
/*   Updated: 2022/11/28 16:01:12 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char			c;
	char			*str;
	void			*p;
	int				n;
	unsigned int	nu;
	int				nx;

	c = 'f';
	printf("\ntest %%f avec c = %c\n", c);
	printf("res ft_print: %d\n", ft_printf("c = %c\n", c));
	printf("res print: %d\n", printf("c = %c\n", c));
	str = "bonjour";
	printf("\ntest %%s avec str = %s\n", str);
	printf("res ft_print: %d\n", ft_printf("s = %s\n", str));
	printf("res print: %d\n", printf("s = %s\n", str));
	str = "bonjour";
	printf("\ntest %%p avec adr = %p\n", str);
	printf("res ft_print: %d\n", ft_printf("adr = %p\n", str));
	printf("res print: %d\n", printf("adr = %p\n", str));
	n = 10;
	printf("\ntest %%d avec n = %d\n", n);
	printf("res ft_print: %d\n", ft_printf("n = %d\n", n));
	printf("res print: %d\n", printf("n = %d\n", n));
	n = 556;
	printf("\ntest %%i avec ni = %i\n", n);
	printf("res ft_print: %d\n", ft_printf("n = %i\n", n));
	printf("res print: %d\n", printf("n = %i\n", n));
	nu = -853;
	printf("\ntest %%u avec nu = %u\n", nu);
	printf("res ft_print: %d\n", ft_printf("nu = %u\n", nu));
	printf("res print: %d\n", printf("nu = %u\n", nu));
	nx = 140;
	printf("\ntest %%x avec nx = %x\n", nx);
	printf("res ft_print: %d\n", ft_printf("nx = %x\n", nx));
	printf("res print: %d\n", printf("nx = %x\n", nx));
	printf("\ntest %%X avec nx = %X\n", nx);
	printf("res ft_print: %d\n", ft_printf("nx = %X\n", nx));
	printf("res print: %d\n", printf("nx = %X\n", nx));
	p = NULL;
	printf("res ft_print: %d\n", ft_printf("p = %p\n", (void *)-1457));
	printf("res print: %d\n", printf("p = %p\n", (void *)-1457));
	return (0);
}
// int    main(void)
// {
//   //  printf("p : %d\n", printf("c: %y &&&& ", 'A'));
//     printf("p : %d\n", ft_printf("c: %j &&&& ", 'A'));
//     printf("p : %d\n", printf("c: %s &&&& ", "Comment vas tu"));
//     printf("p : %d\n", ft_printf("c: %s &&&& ", "Comment vas tu"));
//     printf("p : %d\n", printf("c: %p &&&& ", NULL));
//     printf("p : %d\n", ft_printf("c: %p &&&& ", NULL));
//     printf("p : %d\n", printf("c: %ld &&&& ", -2147483648));
//     printf("p : %d\n", ft_printf("c: %d &&&& ", -2147483648));
//     printf("p : %d\n", printf("c: %i &&&& ", 45));
//     printf("p : %d\n", ft_printf("c: %i &&&& ", 45));
//     printf("p : %d\n", printf("c: %u &&&& ", -100));
//     printf("p : %d\n", ft_printf("c: %u &&&& ", -100));
//     printf("p : %d\n", printf("c: %lx &&&& ", 4294967295));
//     printf("p : %d\n", ft_printf("c: %x &&&& ", 4294967295));
//     printf("p : %d\n", printf("c: %lX &&&& ", 4294967295));
//     printf("p : %d\n", ft_printf("c: %X &&&& ", 4294967295));
//     printf("p : %d\n", printf("c: %% &&&& "));
//     printf("p : %d\n", ft_printf("c: %% &&&& "));
//     printf("p : %d\n", printf("c: %c et %d et %s et %x", 'A', 58, "coucou", 15));
//     printf("p : %d\n", printf("c: %c et %d et %s et %x", 'A', 58, "coucou", 15));
//     printf("p : %d\n", printf(""));
//     printf("p : %d\n", ft_printf(""));
// 	return (0);
// }

/*
FEAT -
FIX - 
WIP - 
NORM - 
PROJ - 
*/