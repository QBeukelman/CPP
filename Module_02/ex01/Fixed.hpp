/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/24 22:19:21 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/25 00:11:21 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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
