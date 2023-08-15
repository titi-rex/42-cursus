/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:01:04 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/15 16:17:02 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONE_BOOK_H__
# define _PHONE_BOOK_H__

class PhoneBook {
	
	private:
	
		int	_privint;
	
	public:
	
		PhoneBook(int const val);
		~PhoneBook(void);
		
		void	hello(void) const;
		void	setPrivint(int const val);
		int		getPrivint(void) const;
		int		compare(PhoneBook *other) const;
	
};

#endif