/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:57:02 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/31 16:52:40 by tlegrand         ###   ########.fr       */
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

    if (str.size() > 10)
        throw std::runtime_error("invalid date => " + str);

    std::stringstream   stream(str);
    char                tmp;

    stream >> date.tm_year >> tmp >> date.tm_mon >> tmp >> date.tm_mday;
    date.tm_year -= 1900;
    date.tm_mon -= 1;
    control = date;
    std::time_t unix_time = std::mktime(&date);
    if (unix_time == -1)
        throw std::runtime_error("can't mktime for: " + str);

    if (control.tm_year != date.tm_year
        || control.tm_mon != date.tm_mon
        ||control.tm_mday!= date.tm_mday)
        throw std::runtime_error("invalid date => " + str);
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
                this->_price[udate] = std::atof(price.c_str());
            }
    }
    catch (std::runtime_error & error)
    {
        in.close();
        throw error;
    }
    in.close();
    if (this->_price.empty() == true)
        throw std::runtime_error("corrupted database");
};

void    BitcoinExchange::error(std::string str)
{
    std::cerr << "Error: " << str << std::endl;
}

void    BitcoinExchange::print(std::string& date, float amount, float rate)
{
    std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
}

float BitcoinExchange::findPrice(std::time_t date)
{
    if (this->_price.count(date) == 1)
        return (this->_price.at(date));
    else
    {
        std::map<std::time_t , float>::iterator it = this->_price.lower_bound(date);
        if (it == this->_price.begin())
            throw std::runtime_error("date too old for database");
        if (it == this->_price.end())
            throw std::runtime_error("date more recent than database");     
        --it;
        return (it->second);
    }
};

float BitcoinExchange::_checkAmount(std::stringstream &stream)
{
    float amount = 0;
    std::string tmp;

    stream >> tmp;
    if (tmp == "")
        throw std::runtime_error("no amount provided");    
    if (amount < 0)
        throw std::runtime_error("not a positive number");
    amount = std::atof(tmp.c_str());
    if (amount > 1000)
        throw std::runtime_error("number too large");
    return (amount);
}

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
            char tmp;
            stream >> date >> tmp;

            if (date == "")
                return ;
            try 
            {
                std::time_t udate = this->_parseDate(date);
                float amount = _checkAmount(stream);
                float rate = this->findPrice(udate);
                this->print(date, amount, rate); 
            }
            catch (std::exception & error)
            {
                this->error(error.what());
            }
        }

    in.close();
}

