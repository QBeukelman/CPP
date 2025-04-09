/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/24 19:56:06 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/09 16:10:23 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	_wholeValue = 0;
	std::cout << "Default constructor called." << std::endl;
}

/*
	Copy constructor - Initialize a new object.
	The values of the original objects members are copied into the new object.
*/
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called." << std::endl;
	*this = other;
}

/*
	Copy assignment operator - Deep copy of existing object.
	Assign one object to another using the `=` operator.
*/
Fixed	&Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other) {	// Prevent self-assignment
		_wholeValue = other._wholeValue;
	}
	return (*this);	// Return the current object to allow chaining of assignment
}

Fixed::~Fixed() {
	std::cout << "Destructor called." << std::endl;
}

int		Fixed::getWholeValue(void) const {
	std::cout << "getWholeValue() member function called." << std::endl;
	return (this->_wholeValue);
}

void	Fixed::setWholeValue(int const newValue) {
	this->_wholeValue = newValue;
}
