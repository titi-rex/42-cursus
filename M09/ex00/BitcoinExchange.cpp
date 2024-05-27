/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:57:02 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/27 15:18:54 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {};
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {*this = src;};
BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& src) 
{
    if (&src != this)
        this->_price = src._price;
    return (*this);
};

BitcoinExchange::~BitcoinExchange(void) {};

bool    BitcoinExchange::_checkDate(std::string str)
{
    for(std::size_t i =0; i < str.len(); ++i)
    {
        
    }
};
bool    BitcoinExchange::_checkValue(std::string str)
{
    
};


int BitcoinExchange::_parseDate(std::string str)
{
    std::tm date;
    std::memset(&date, 0, sizeof(date));

    

    date.tm_year = std::atoi(str.c_str());
    str.erase(0, 5);
    date.tm_mon = std::atoi(str.c_str());
    str.erase(0, 3);
    date.tm_mday = std::atoi(str.c_str());
    return (std::mktime(&date));
}

bool BitcoinExchange::loadPriceDb(std::string path)
{
    std::ifstream in;
    
    in.open(path.c_str(), std::ios::in);
    if (in.good() == false)
	{
		in.close();
		return(false);
	}
    std::string tmp;
    std::getline(in, tmp);
    while(!in.eof())
    {
        std::string date, price;
        std::getline(in, date, ',');
        std::getline(in, price);
        if (date == "")
            break;
        this->_price[this->_parseDate(date)] = std::atof(price.c_str());
    }
    in.close();
    return (true);
};


int BitcoinExchange::findPrice(int date)
{
    (void)date;
    std::cout << this->_price << std::endl;
    return(0);
};