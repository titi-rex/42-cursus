/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:10:23 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/03 16:41:14 by tlegrand         ###   ########.fr       */
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

bool is_char(std::string input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		return true;
	return false;
};

void	print_char_fist(std::string input)
{
	char	c = input[0];

	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl<< "double: " << static_cast<float>(c) << std::endl;
}

bool is_int(std::string input)
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

void	print_int_fist(std::string input)
{
	int	i = strtol(input.c_str(), NULL, 10);

	if (isprint(static_cast<char>(i)))
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(i) << "f" << std::endl<< "double: " << static_cast<float>(i) << std::endl;
}

int is_float(std::string input)
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

void	print_float_fist(std::string input, int wit)
{
	std::string	reff[3] = {"nanf", "-inff", "+inff"};
	std::string	ref[3] = {"nan", "-inf", "+inf"};

	for (int i=0; i<3; ++i)
	{
		if (input.compare(reff[i]) == 0)
		{
			std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl;
			std::cout << "float: " << reff[i] << std::endl << "double: " << ref[i] << std::endl;
			return ;
		}
	}

	float	f = strtof(input.c_str(), NULL);
	
	if (isprint(static_cast<char>(f)))
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl<< "double: " << static_cast<float>(f) << std::endl;
}

bool is_double(std::string input)
{
	size_t		i = 0;
	std::string	ref[3] = {"nan", "-inf", "+inf"};

	
	for (int i=0; i<3; ++i)
	{
		if (input.compare(ref[i] + "f") == 0)
			return true;
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
		return false;
	return true;
}

void	print_double_fist(std::string input)
{
	float	f = strtof(input.c_str(), NULL);

	if (isprint(static_cast<char>(f)))
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl<< "double: " << static_cast<float>(f) << std::endl;
}

void	ScalarConverter::convert(std::string input) 
{
	std::string	ref[3] = {"nan", "-inf", "+inf"};
	long int	c;
	double		d;
	char**		endptr = NULL;
	int	ret = 0;

	// for (int i=0; i<3; ++i)
	// {
	// 	if (ref[i].compare(input) == 0 || input.compare(ref[i] + "f") == 0)
	// 	{
	// 		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl;
	// 		std::cout << "float: " << ref[i] << "f" << std::endl;
	// 		std::cout << "double: " << ref[i] << std::endl;
	// 		return;
	// 	}
	// }

	if (is_char(input))
		print_char_fist(input);
	else if (is_int(input))
		print_int_fist(input);
	else if ((ret = is_float(input) != -1))
		print_float_fist(input, ret);
	// else if (is_double(input))
	// 	print_double_fist(input);
	else
		std::cout << "Unknow literals" << std::endl;
		
	return ;
	if(input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
	{
		std::cout << "char: " << input[0] << std::endl << "int: " << int(input[0]) << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << float(input[0]) << "f" << std::endl << "double: " << double(input[0]) << std::endl;
	}
	else
	{
		c = std::strtol(input.c_str(), NULL, 10);
		if (c == LONG_MAX || c == LONG_MIN || c > INT_MAX || c < INT_MIN)
			std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl;
		else
		{
			if (isprint(c))
				std::cout << "char: " << static_cast<char>(c) << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(c) << std::endl;
		}
		d = std::strtod(input.c_str(), endptr);
		if (d == HUGE_VAL)
			std::cout << "float: impossible" << std::endl << "double: impossible" << std::endl;
		else
		{
			std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(d) << "f" << std::endl<< "double: " << d << std::endl;
		}
	}

};
