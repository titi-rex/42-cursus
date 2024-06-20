/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:01:40 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/25 12:43:19 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MUTANT_STACK_H__
# define _MUTANT_STACK_H__
# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public	:
		MutantStack(void) {};
		MutantStack(const MutantStack& src) : std::stack<T>(src) {};
		MutantStack&	operator=(const MutantStack& src) 
		{
			this->std::stack<T>::operator=(src);
			return (*this);
		};
		~MutantStack(void) {};

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin(void) {return (this->c.begin());};
		iterator	end(void) {return (this->c.end());};

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		const_iterator	cbegin(void) {return (this->c.cbegin());};
		const_iterator	cend(void) {return (this->c.cend());};
};

#endif
