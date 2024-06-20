/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:02:06 by tlegrand          #+#    #+#             */
/*   Updated: 2023/06/06 21:16:31 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

int	main(void)
{
	char	*s;
	int		u;

	s = NULL;
	u = 584;
	printf("ret ft :%d\n", ft_printf("hello :% #p:\n", &s));
	printf("ret exp :%d\n", printf("hello :% #p:\n", &s));
}
