/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:57:02 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/27 19:45:22 by tlegrand         ###   ########.fr       */
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


std::time_t BitcoinExchange::_parseDate(std::string& str)
{
    std::tm date;
    std::tm control;
    std::memset(&date, 0, sizeof(date));
    std::memset(&control, 0, sizeof(control));

    std::stringstream   stream(str);
    char                tmp;

    stream >> date.tm_year >> tmp >> date.tm_mon >> tmp >> date.tm_mday;
    date.tm_year -= 1900;
    date.tm_mon -= 1;
    control = date;
    std::time_t unix_time = std::mktime(&date);

    if (control.tm_year != date.tm_year
        || control.tm_mon != date.tm_mon
        ||control.tm_mday!= date.tm_mday)
        return (-1);
    return (unix_time);
}

void BitcoinExchange::loadPriceDb(std::string path)
{
    std::ifstream in;
    
    in.open(path.c_str(), std::ios::in);
    if (in.good() == false)
        throw std::runtime_error("can't open database file at: " + path);
    std::string tmp;
    std::getline(in, tmp);
    try 
    {
        while(!in.eof())
            {
                std::string date, price;
                std::getline(in, date, ',');
                std::getline(in, price);
                if (date == "")
                    break;
                std::time_t udate = this->_parseDate(date);
                if (udate == -1)
                    throw std::runtime_error("invalid date in database: " + date);
                this->_price[udate] = std::atof(price.c_str());
            }
    }
    catch (std::runtime_error & error)
    {
        in.close();
        throw error;
    }
    in.close();
};

void    BitcoinExchange::error(std::string str)
{
    std::cerr << "Error: " << str << std::endl;
}

void    BitcoinExchange::print(std::string& date, float amount, float value)
{
    std::cout << date << " => " << amount << " = " << amount * value << std::endl;
}

float BitcoinExchange::findPrice(std::time_t date)
{

    if (this->_price.count(date) == 1)
        return (this->_price.at(date));
    else
    {
        std::map<std::time_t , float>::iterator it = this->_price.lower_bound(date);
        if (it != this->_price.begin())
            --it;
        return (it->second);
    }
};

void BitcoinExchange::compute(std::string path)
{
    std::ifstream in;
    
    in.open(path.c_str(), std::ios::in);
    if (in.good() == false)
        throw std::runtime_error("can't open input file at: " + path);

    std::string line;
    std::getline(in, line);

    while(std::getline(in, line))
        {
            std::stringstream stream(line);
            std::string date;
            float amount = 0;
            char tmp;
            stream >> date >> tmp;

            if (date == "")
                return ;
            std::time_t udate = this->_parseDate(date);
            if (udate == -1)
            {
                this->error("invalid date => " + date);
                continue;
            }
            if (!stream)
            {
                this->error("no amount provided");
                continue;
            }
            stream >> amount;
            if (amount < 0)
            {
                this->error("not a positive number");
                continue;
            }
            if (amount > 1000)
            {
                this->error("number too large");
                continue;
            }
            float value = this->findPrice(udate);
            this->print(date, amount, value);
        }

    in.close();
}

// date | value
// invalid date | value
// date | invalid value
// date | no value