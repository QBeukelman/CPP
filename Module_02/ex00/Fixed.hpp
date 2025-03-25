/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/24 19:56:03 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/24 22:18:37 by quentinbeuk   ########   odam.nl         */
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
		~Fixed();								// Destructor

		int		getWholeValue(void) const;
		void	setWholeValue(int const newValue);
};

#endif
