/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:47:16 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/13 21:52:43 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONTACT_H__
# define _CONTACT_H__
# include <string>
# include <iostream>
# include <iomanip>

class Contact {
	
	std::string	_fname;
	std::string	_lname;
	std::string	_nname;
	std::string	_pnumber;
	std::string	_secret;
	
	public:
	
		Contact(void);
		
		std::string	getFname(void) const;
		std::string	getLname(void) const;
		std::string	getPnumber(void) const;
		std::string	getNname(void) const;
		std::string getSecret(void) const;

		void		display(void) const;
		void		fillContact(std::string fname, std::string lname, 
			std::string pnumber, std::string nname, std::string secret);	
};

#endif