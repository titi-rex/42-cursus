/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:03:46 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/10 14:03:46 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
# define __FIXED_H__
# include <iostream>

class Fixed {
	
	private	:
		int					_rawbits;
		static const int	_point;

	public	:

		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& F);
		~Fixed(void);
		
		Fixed&		operator=(const Fixed& F);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

};

std::ostream&	operator<<(std::ostream& os, const Fixed& F);

#endif
