/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:40:11 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/05 21:59:22 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DATA_H__
# define _DATA_H__
# include <string>

typedef unsigned int long	uintptr_t;

typedef struct s_data
{
	int			id;
	void*		ptr;
	std::string	name;
}	Data;

#endif
