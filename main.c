/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:42:16 by tlegrand          #+#    #+#             */
/*   Updated: 2022/11/26 14:23:57 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char			c;
	char			*str;
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


	ft_putnbr_base((unsigned int)nu, "0123456789");
	ft_putchar('\n');
	ft_putuint(nu);











/*
	ft_printf("\nputnbrbase: \t");
	ft_putnbr_base(INT_MIN, "0123456789");

	printf("res ft_print: %d\n", ft_printf("hello my name is %s, i'm %d, %c love %s\n", "Lou", 27, 'i', "chocolat"));
	printf("res print: %d\n", printf("hello my name is %s, i'm %d, %c love %s\n", "Lou", 27, 'i', "chocolat"));

	printf("res ft_print: %d\n", ft_printf(" %% hehe\n"));
	printf("res print: %d\n", printf(" %% hehe\n"));

	ft_printf("hello %s!\n", "john", "marc");
//	ft_printf("hello %s and %s!\n", "john");

	str = NULL;
	printf("res print: %d\n", printf("NULL : %s NuLL\n", str));
	printf("res ft_print: %d\n", ft_printf("NULL : %s NuLL\n", str));
*/





	// printf("d = %d\n", f);
	// printf("i = %i\n", n);
	// printf("i = %i\n", f);
	// printf("u = %u\n", n);
	// printf("u = %u\n", f);
	// printf("flags : space\t:% dendl\n", n);
	// printf("flags : +\t:%+dendl\n", n);
	// printf("flags : -\t:%-dendl\n", n);
	// printf("flags : 0\t:%0dendl\n", n);
	// printf("flags : .\t:%.dendl\n", n);
	// printf("flags : #\t:error undefined behavior\n");

	// printf("mixed flags : \n");
	// printf("flags : space + : space is ignored\n");
	// printf("flags : 0 . : 0 is ignored\n");
	// printf("flags : 0 - : 0 is ignored\n");

	return (0);
}

/*
FEAT -
FIX - 
WIP - 
NORM - 
PROJ - 
*/