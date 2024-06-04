/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:31:21 by tlegrand          #+#    #+#             */
/*   Updated: 2024/06/04 11:24:08 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __RPN__
# define __RPN__
# include <vector>
# include <deque>

# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <ctime>
# include <algorithm>

# include <exception>
# include <unistd.h> 

// print
template <typename T>
void printContainer(const T& m)
{
    int i = 0;

    for (typename T::const_iterator it = m.begin(); it != m.end(); ++it)
    {
        std::cout << *it << " ";
        if (++i > 10)
        {
            std::cout << " [...]";
            break ;
        }
    }
    std::cout << std::endl;
}


template <typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T>& m)
{
    for (size_t i = 0; i != m.size(); ++i)
    {
        if (i + 1 == m.size())
        {
            if (i % 2 == 0)
                os << "[" << m.at(i) << "]";
            else
                os << m.at(i) << ") ";
        }
        else if (i % 2 == 0)
            os << "(" << m.at(i) << " ";
        else
            os << m.at(i) << ") ";
    }
    return (os);
}

template <typename T>
std::ostream& operator<<(std::ostream &os, const std::deque<T>& m)
{
    for (size_t i = 0; i != m.size(); ++i)
    {
        if (i + 1 == m.size())
        {
            if (i % 2 == 0)
                os << "[" << m.at(i) << "]";
            else
                os << m.at(i) << ") ";
        }
        else if (i % 2 == 0)
            os << "(" << m.at(i) << " ";
        else
            os << m.at(i) << ") ";
    }
    return (os);
}


// logic utils
template <typename T> T max(T& a, T& b)
{
	return ((a > b) ? a : b);
}

template <typename T> T min(T& a, T& b)
{
	return ((a < b) ? a : b);
}


template <typename T>
void swap(T& a, T& b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}



template <typename C> 
bool validate(C ref, C& sorted)
{
    for(typename C::iterator it = sorted.begin(); it != sorted.end(); ++it)
    {
        typename C::iterator i = std::find(ref.begin(), ref.end(), *it);
        if (i != ref.end())
            ref.erase(i);
        if ((it + 1) != sorted.end())
        {
            if (*it > *(it + 1))
            {
                std::cerr << "Error: not sorted: " << *it << " " << *(it + 1) << std::endl;
                return (false);
            }
        }
    }
    if (ref.size() != 0)
    {
        std::cerr << "Error: missing numbers: ";
        printContainer(ref);
        return (false);
    }
    return (true);
}


class PmergeMe 
{
    private:
        bool    _verbose;
        int     _depht;
        int     _dVerbosity;

        void    _dive(void);
        void    _rise(void);
        size_t  _getNextJacobstahl(int first, bool reset=false);

        template <typename T> void  _logger(const std::string& str, const T& obj);
        template <typename C> int   _getOdd(C& input);
        template <typename C> void  _getSequence(C& input, C& seq);
        template <typename C> void  _sortPairs(C& input, const C& sorted);
        template <typename C> void  _insertDicho(const C& input, C& sorted);

        PmergeMe(void);
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& src);

    public:
        PmergeMe(const bool verbose=false, const int depth_verbosity=0);
        ~PmergeMe(void);

        template <typename T> double timer(T& obj1, T& obj2);
        template <typename C> void compute(C& input, C& sorted);
        template <typename T> T& sortAndSwap(T& a, T& b);
};


template <typename T>
double PmergeMe::timer(T& obj1, T& obj2)
{
    std::clock_t start = std::clock();
    compute(obj1, obj2);
    std::clock_t end = std::clock();
    return (static_cast<double>(end - start));
}


template <typename T>
void PmergeMe::_logger(const std::string& str, const T& obj)
{
    if (_verbose && _depht >= _dVerbosity)
        std::cout << "d" << _depht << ": " << str << ": " << obj << std::endl;
}

template <typename T>
T& PmergeMe::sortAndSwap(T& a, T& b)
{
    if (a > b)
        swap(a, b);
    return (b);    
};

template <typename C> 
void PmergeMe::compute(C& input, C& sorted)
{
    _dive();
    int odd = _getOdd(input);
    if (input.size() > 2)
    {
        C   seq;

        _getSequence(input, seq);
        compute(seq, sorted);
        _logger("Input", input);
        _logger("Sorted", sorted);
        _sortPairs(input, sorted);
        _insertDicho(input, sorted);
    }
    else
    {
        _logger("MAX DEPTH", _depht);
        sorted = input;
        sortAndSwap(sorted.at(0), sorted.at(1));
        _logger("Input", input);
        _logger("Sorted", sorted);
    }
    if (odd != -1)
    {
        _logger("Insert alone", odd);
        sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), odd), odd);
    }
    _logger("Sorted", sorted);
    _rise();
}

template <typename C>
int    PmergeMe::_getOdd(C& input)
{
    int odd = -1;
    if (input.size() % 2 == 1)
    {
        odd = input.back();
        input.pop_back();
        _logger("Alone", odd);
    }
    return (odd);
};

template <typename C>
void    PmergeMe::_getSequence(C& input, C& seq)
{
    for (size_t i = 0; i < input.size(); i += 2) 
    {
        seq.push_back(sortAndSwap(input.at(i), input.at(i + 1)));
    }
    _logger("Input size", input.size());
    _logger("Input", input);
    _logger("Sequence", seq);
};

template <typename C>
void    PmergeMe::_sortPairs(C& input, const C& sorted)
{
    for (size_t i = 0, j = 1; i < sorted.size(); ++i, j += 2)
    {
        _logger("Search", sorted.at(i));
        typename C::iterator it = std::find(input.begin() + j, input.end(), sorted.at(i));
        if (*it == input.at(j))
        {
            _logger("No swap needed", *it);
            continue;
        }
        _logger("Swap with", input.at(j));
        swap(*(it - 1), input.at(j - 1));
        swap(*it, input.at(j));
    }
    _logger("Input with sorted pairs", input);
}


template <typename C>
void     PmergeMe::_insertDicho(const C& input, C& sorted)
{
    _logger("Insert first", input.at(0));
    sorted.insert(sorted.begin(), input.at(0));
    _logger("Sorted", sorted);
    int size = (input.size() - 2) / 2;
    int i = 0;
    while (i < size)
    {
        int nj = _getNextJacobstahl(i);
        int left = size - i;
        int space = min(nj, left);
        for (int k=0; k < space; ++k)
        {
            int l = 2 * (k + i) + 2;
            _logger("Insert", input.at(l));
            sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), input.at(l)), input.at(l));
            _logger("Sorted", sorted);
        }
        i += space;
    }
    _getNextJacobstahl(0, true);
}


#endif
