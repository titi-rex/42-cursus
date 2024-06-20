/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:01:04 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/18 10:56:37 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONE_BOOK_H__
# define _PHONE_BOOK_H__
# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>

# define MAX_CONTACT 8

class PhoneBook 
{
	private :
		int		_idx;
		int		_ncontact;
		Contact	_contact[MAX_CONTACT];
	
		void	_display_field(std::string str) const;
		void	_display(void) const;
	
	public :
		PhoneBook(void);
		
		void	add_contact(std::string data[5]);
		void	search(void) const;
};

#endif