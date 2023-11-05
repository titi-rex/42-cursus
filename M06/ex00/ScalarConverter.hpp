/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:14:57 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/05 21:32:01 by tlegrand         ###   ########.fr       */
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
	private	:
		static bool	is_char(std::string input);
		static void	print_char_fist(std::string input);
		static bool 	is_int(std::string input);
		static void	print_int_fist(std::string input);
		static int		is_float(std::string input);
		static void	print_float_fist(std::string input, int wit);
		static int 	is_double(std::string input);
		static void	print_double_fist(std::string input, int wit);
		

	public	:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter&	operator=(const ScalarConverter& src);
		~ScalarConverter(void);

		static void	convert(std::string input);
};

#endif
