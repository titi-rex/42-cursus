/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:01:04 by tlegrand          #+#    #+#             */
/*   Updated: 2023/08/17 00:03:24 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONE_BOOK_H__
# define _PHONE_BOOK_H__
#include "Contact.hpp"

class PhoneBook 
{
	private:
	
		int		_idx;
		int		_ncontact;
		Contact	_contact[3];
	
		void	_display_field(std::string str) const;
		void	_display(void) const;
	
	public:
	
		PhoneBook(void);
		
		void	add_contact(std::string data[5]);
		void	search(void) const;
};

#endif