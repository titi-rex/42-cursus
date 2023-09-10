/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:03:46 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/10 12:15:38 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
# define __FIXED_H__

class Fixed {
	
	private	:
		int					_value;
		static const int	_bit;

	public	:

		Fixed(void);
		Fixed(const Fixed& F);
		~Fixed(void);
		Fixed& operator=(const Fixed& F);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);


};

#endif
