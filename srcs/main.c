/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:20:34 by tlegrand          #+#    #+#             */
/*   Updated: 2023/05/04 15:47:49 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	char	*str = "hello loulou";

	printf(" ret %d \n", ft_printf("test %% :%10.9s:\n", str));
		printf("expected ret %d \n", printf("test %% :%10.9s:\n", str));

}
