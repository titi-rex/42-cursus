/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:01:40 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/21 17:16:16 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MUTANT_STACK_H__
# define _MUTANT_STACK_H__
# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	
	private	:

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
};

#endif
