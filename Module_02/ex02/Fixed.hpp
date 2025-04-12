/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:07:46 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/11 12:30:22 by qbeukelm         ###   ########.fr       */
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
		Fixed();											// Default constructor
		~Fixed();											// Destructor
		Fixed(const int newInt);							// Converts int to fixed-point value
		Fixed(const float newFloat);						// Converts float to fixed-point value
		Fixed(const Fixed& other);							// Copy constructor
		Fixed& operator=(const Fixed& other);				// Copy assignment operator

		// -------------------------------------------------	Comparitor
		bool	operator>(const Fixed value) const;
		bool	operator<(const Fixed value) const;
		bool	operator>=(const Fixed value) const;
		bool	operator<=(const Fixed value) const;
		bool	operator==(const Fixed value) const;
		bool	operator!=(const Fixed value) const;

		// -------------------------------------------------	Arithmetic operators
		Fixed	operator+(const Fixed value) const;
		Fixed	operator-(const Fixed value) const;
		Fixed	operator*(const Fixed value) const;
		Fixed	operator/(const Fixed value) const;

		// -------------------------------------------------	Incriment/Decrement operators
		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);

		// -------------------------------------------------	Static member functions
		static			Fixed& min(Fixed& a, Fixed& b);
		static const	Fixed& min(const Fixed& a, const Fixed& b);
		static			Fixed& max(Fixed& a, Fixed& b);
		static const	Fixed& max(const Fixed& a, const Fixed& b);
		
		// -------------------------------------------------	Member functions
		int		getWholeValue(void) const;
		float	toFloat(void) const;
};

std::ostream&	operator<<(std::ostream &out, Fixed const &fixed);

#endif
