/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:01:40 by tlegrand          #+#    #+#             */
/*   Updated: 2023/11/20 14:19:53 by tlegrand         ###   ########.fr       */
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
		MutantStack(void);
		MutantStack(const MutantStack& src);
		MutantStack&	operator=(const MutantStack& src);
		~MutantStack(void);

		typedef typename MutantStack<T>::container_type::iterator iterator;
		typedef typename MutantStack<T>::container_type::const_iterator const_iterator;
		
		iterator	begin(void);
		iterator	end(void);

		const_iterator	cbegin(void);
		const_iterator	cend(void);
};

# include "MutantStack.tpp"

#endif
