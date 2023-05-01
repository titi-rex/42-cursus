/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:50:35 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/01 20:12:17 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


int	main(void)
{
	char	*str;

	str = "hello";
	printf(":%s:\n", str);
	printf(":%--20s:\n", str);
	return (0);
}

/*

multijoin(tab)
sum up

-&/. or 0
&
space or +
& 
#
6 flag with 2 potential value (widt and preci)

conversion :
c			:	take int convret in char
s			:	take char* and print it	(null) if NULL
p			:	take void* and print in hexa (nil) if NULL
d i			:	take sined int and convert in decimal notation 
o u x X		:	take unsigned int and convert in (o)ctal (u)nsigned decimal he(x)a 
	and HE(X)A
%			:	print % no arg needed ignore flag

flags : 
combo
-	:	(override 0) converted value is left adjusted padding by default is blank
0	:	pad with 0 for d i u o x X  for other conv is undefined
.	:	(override 0) precision should be followed by a decima lvalue, if notm precision is taken 
	has 0, negative value cancel precision (? test show other thing). precison is the minimum number of digit
		to appear for diouxX and maximum char to print for s no efffect for c and p (error msg)

and field minimum width 	:	decimal digitstring non zero first digit 
(pad with space on left) negativ is - flag with positive field minum field is alway 
converstion lenght

alone 
#			: value converted to alternate form ie :
for o	: outut prefixed by 0 if firs tchar wasnt 0
for x/X	: output prefixed by 0x/0X
other conv is undefined

 (space)	: left a blank before a positive number (or empty string 
 	produced by signed conv 
 +			: (override space) place a sign (+ or -) before a number produced by conv ??? 
	by default only - are placed before number


%[flags][width][precision]conversion

unkmowflag just print all 
*/