/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:41:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/24 15:22:13 by tlegrand         ###   ########.fr       */
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
#define BUFFER_SIZE 1024

int	get_file(const char* const pathanme, std::string& str_file)
{
	std::ifstream	in;
	char			buffer[BUFFER_SIZE];
	
	in.open(pathanme, std::ios::in);
	if (in.good() == false)
	{
		in.close();
		return (1);
	}
	while (!in.eof())
	{
		in.get(buffer, BUFFER_SIZE, '\0');
		str_file.append(buffer);
	}
	in.close();
	return (0);
}

int	write_file(char *pathname, std::string data)
{
	std::ofstream	out;
	std::string		name(pathname);
	
	name += ".replace";
	out.open(name.data(), std::ios::out);
	if (out.good() == false)
	{
		out.close();	
		return (1);
	}
	out << data;
	out.close();
	return (0);
}

void	search_n_destroy(std::string& data, const char *s1, const char *s2)
{
	const std::string	search(s1);
	const std::string	replace(s2);
	std::size_t			i = 0;
	
	while (i < data.size())
	{
		if (data.compare(i, search.size(), search) == 0)
		{
			data.erase(i, search.size());
			data.insert(i, replace);
		}
		++i;
	}
}

int	main(int ac, char** arg)
{
	if (ac != 4)
		return (1);
	std::string		buff;

	if (get_file(arg[1], buff))
		return (1);
	search_n_destroy(buff, arg[2], arg[3]);
	if (write_file(arg[1], buff))
		return (1);
	return (0);	
}
