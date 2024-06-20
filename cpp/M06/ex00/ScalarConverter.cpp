/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:10:23 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/05 21:33:12 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {};

ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; };

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src) 
{
	if (this == &src)
		return (*this);
	return (*this);
};

ScalarConverter::~ScalarConverter(void) {};

bool	ScalarConverter::is_char(std::string input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		return true;
	return false;
};

void	ScalarConverter::print_char_fist(std::string input)
{
	char	c = input[0];

	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl<< "double: " << static_cast<float>(c) << std::endl;
}

bool	ScalarConverter::is_int(std::string input)
{
	size_t	i = 0;

	if (input[0] == '-')
		++i;
	while (isdigit(input[i]))
		++i;
	if (input[i])
		return false;
	return true;
}

void	ScalarConverter::print_int_fist(std::string input)
{
	int	i = strtol(input.c_str(), NULL, 10);

	if (isprint(static_cast<char>(i)))
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(i) << "f" << std::endl<< "double: " << static_cast<float>(i) << std::endl;
}

int ScalarConverter::is_float(std::string input)
{
	size_t		i = 0;
	std::string	reff[3] = {"nanf", "-inff", "+inff"};

	for (int j=0; j<3; ++j)
	{
		if (reff[j].compare(input) == 0)
			return (j);
	}
	if (input[0] == '-')
		++i;
	while (isdigit(input[i]))
		++i;
	if (input[i] == '.')
		++i;
	while (isdigit(input[i]))
		++i;
	if (input[i] == 'f')
		++i;
	if (input[i])
		return (-1);
	return (3);
}

void	ScalarConverter::print_float_fist(std::string input, int wit)
{
	std::string	ref[3] = {"nan", "-inf", "+inf"};

	if (wit != 3)
	{
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl;
		std::cout << "float: " << ref[wit] << "f" << std::endl << "double: " << ref[wit] << std::endl;
		return ;
	}

	float	f = strtof(input.c_str(), NULL);
	
	if (isprint(static_cast<char>(f)))
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl<< "double: " << static_cast<float>(f) << std::endl;
}

int ScalarConverter::is_double(std::string input)
{
	size_t		i = 0;
	std::string	ref[3] = {"nan", "-inf", "+inf"};

	for (int j=0; j<3; ++j)
	{
		if (ref[j].compare(input) == 0)
			return (j);
	}
	if (input[0] == '-')
		++i;
	while (isdigit(input[i]))
		++i;
	if (input[i] == '.')
		++i;
	while (isdigit(input[i]))
		++i;
	if (input[i])
		return (-1);
	return (3);
}

void	ScalarConverter::print_double_fist(std::string input, int wit)
{
	std::string	ref[3] = {"nan", "-inf", "+inf"};

	if (wit != 3)
	{
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl;
		std::cout << "float: " << ref[wit] << "f" << std::endl << "double: " << ref[wit] << std::endl;
		return ;
	}
	
	double	d = strtod(input.c_str(), NULL);

	if (isprint(static_cast<char>(d)))
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(d) << "f" << std::endl<< "double: " << d << std::endl;
}

void	ScalarConverter::convert(std::string input) 
{
	int	ret = 0;

	if (is_char(input))
		print_char_fist(input);
	else if (is_int(input))
		print_int_fist(input);
	else if ((ret = is_float(input)) != -1)
		print_float_fist(input, ret);
	else if ((ret = is_double(input)) != -1)
		print_double_fist(input, ret);
	else
		std::cout << "Unknow literals" << std::endl;
};
