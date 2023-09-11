/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:03:46 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/11 13:58:00 by tlegrand         ###   ########.fr       */
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
		
		Fixed&	operator=(const Fixed& F);
		
		Fixed	operator+(const Fixed& F) const;
		Fixed	operator-(const Fixed& F) const;
		Fixed	operator*(const Fixed& F) const;
		Fixed	operator/(const Fixed& F) const;
		
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		bool	operator>(const Fixed& F) const;
		bool	operator<(const Fixed& F) const;
		bool	operator>=(const Fixed& F) const;
		bool	operator<=(const Fixed& F) const;
		bool	operator==(const Fixed& F) const;
		bool	operator!=(const Fixed& F) const;

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;

		static Fixed&		min(Fixed& F1, Fixed& F2);
		static const Fixed&	min(const Fixed& F1, const Fixed& F2);
		static Fixed&		max(Fixed& F1, Fixed& F2);
		static const Fixed&	max(const Fixed& F1, const Fixed& F2);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& F);

#endif
