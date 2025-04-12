/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:19:21 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/11 12:29:17 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					_wholeValue;
		static const int	_fractionalValue = 8;

	public:
		Fixed();								// Default constructor
		Fixed(const Fixed& other);				// Copy constructor
		Fixed& operator=(const Fixed& other);	// Copy assignment operator
		Fixed(const int newInt);				// Converts int to fixed-point value
		Fixed(const float newFloat);			// Converts float to fixed-point value
		~Fixed();								// Destructor

		int		getWholeValue(void) const;
		void	setWholeValue(int const newValue);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream &out, Fixed const &fixed);

#endif
