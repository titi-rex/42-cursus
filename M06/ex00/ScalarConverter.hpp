/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:14:57 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/03 15:33:51 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCALAR_CONVERTER_H__
# define _SCALAR_CONVERTER_H__
# include <string>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <climits>
# include <cmath>

class ScalarConverter 
{
	public	:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter&	operator=(const ScalarConverter& src);
		~ScalarConverter(void);

		static void	convert(std::string input);
};

#endif
