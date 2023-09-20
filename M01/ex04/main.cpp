/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:41:42 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/20 15:25:57 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
