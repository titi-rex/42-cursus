/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:18:45 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/28 10:35:52 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BTC_H__
# define __BTC_H__
# include <map>
# include <string>
# include <fstream>
# include <iostream>
# include <exception>
# include <cstdlib>
# include <ctime>
# include <cstring>

# include <sstream>
 


class BitcoinExchange
{
    private:
        std::map<std::time_t, float>    _price;
        std::time_t                     _parseDate(std::string& str);
        
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange& operator=(const BitcoinExchange& src);
        ~BitcoinExchange(void);

        void    loadPriceDb(std::string path);
        void    compute(std::string path);
        float   findPrice(std::time_t date);

        void    print(std::string& date, float amount, float value);
        void    error(std::string str);
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
