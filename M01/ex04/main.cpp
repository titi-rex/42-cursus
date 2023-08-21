/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:41:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/22 00:11:01 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2.
It will open the file <filename> and copies its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.
Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!
Of course, handle unexpected inputs and errors. You have to create and turn in your
own tests to ensure your program works as expected.
10
*/
/*
#include <fstream>
#include <limits>

ifstream file;
file.open(name,std::ios::in|std::ios::binary);
file.ignore( std::numeric_limits<std::streamsize>::max() );
std::streamsize length = file.gcount();
file.clear();   //  Since ignore will have set eof.
file.seekg( 0, std::ios_base::beg );
*/

#include <iostream>
#include <fstream>
#define BUFFER_SIZE 24


int	stringContent(const std::string small, const std::string big)
{
	std::size_t	i = 0;
	int			k = 0;
	
	if (small.size() > big.size())
		return (-1);
	while (k < big.size() - small.size())
	{
		i = 0;	
		while (small.at(i) && big.at(k + i) && small.at(i) == big.at(k + i))
			++i;
		if (i == small.size())
			return (k);
		++k;
	}
	return (-1);
}


int	sed(std::ofstream out, const char* const r_buffer, const std::string s, const std::string r)
{
	std::string	buffer();
	std::size_t	i = 0;
	
	
	return (0);
}

int	main(int ac, char** arg)
{
	if (ac != 4)
		return (1);
	std::ifstream	in;
	std::ofstream	out;
	std::string		name;
	in.open(arg[1], std::ios::in);
	name = arg[1];
	name += ".replace";
	out.open(name.data(), std::ios::out);



	
	std::string		to_search(arg[2]);
	std::string		to_replace(arg[3]);
	char			r_buff[BUFFER_SIZE];


	while (!in.eof())
	{
		in.get(r_buff, BUFFER_SIZE, '\0');
		std::cout << "content input :" << r_buff << std::endl;
		sed(out, r_buff, to_search, to_replace);
	}


	
	in.close();
	out.close();
		
	return (0);	
}
