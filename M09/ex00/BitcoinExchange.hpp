/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:18:45 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/27 15:17:29 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BTC_H__
# define __BTC_H__
# include <map>
# include <string>
# include <fstream>
# include <iostream>
# include <cstdlib>
# include <ctime>
#include <cstring>
#include <locale>
#include <sstream>
 


class BitcoinExchange
{
    private:
        std::map<int, float>    _price;
        int                     _parseDate(std::string str);
        bool                    _checkDate(std::string str);
        bool                    _checkValue(std::string str);
        
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange& operator=(const BitcoinExchange& src);
        ~BitcoinExchange(void);
        
        bool    loadPriceDb(std::string path);
        int     findPrice(int date);
};

template <typename T, typename U>
std::ostream& operator<<(std::ostream &os, const std::map<T, U> m)
{
	for (typename std::map<T, U>::const_iterator it = m.begin(); it != m.end(); ++it)
	{
		os << (it->first) << ":" << (it->second) << std::endl;
	}
	return (os);
}

#endif
