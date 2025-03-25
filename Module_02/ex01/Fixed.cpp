/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/24 22:19:18 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/24 23:01:00 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	_wholeValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_wholeValue = other._wholeValue;
}

Fixed	&Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &other) {
		_wholeValue = other._wholeValue;
	}
	return (*this);
}

/*
	Constructor - Assgins `wholeValue` to `newInt` value.
*/
Fixed::Fixed(const int newInt) {
	std::cout << "Int constructor called" << std::endl;
	this->_wholeValue = newInt << _fractionalValue;
}

/*
	Constructor - Assigns `wholeValue` to `newFloat` value.
*/
Fixed::Fixed(const float newFloat) {
	std::cout << "Int constructor called" << std::endl;
	this->_wholeValue = roundf(newFloat * (1 << _fractionalValue));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}


int		Fixed::getWholeValue(void) const {
	std::cout << "getWholeValue() member function called" << std::endl;
	return (this->_wholeValue);
}

void	Fixed::setWholeValue(int const newValue) {
	this->_wholeValue = newValue;
}

float	Fixed::toFloat(void) const {
	return ((float)_wholeValue / (float)(1 << _fractionalValue));
}

int		Fixed::toInt(void) const {
	return (_wholeValue >> _fractionalValue);
}

/*
	Overload insertion operator - Operation `.toFloat()` redirects floating-point to 
	output stream `out`.
*/
std::ostream&	operator<<(std::ostream& out, const Fixed& value) {
	out << value.toFloat();
	return (out);
}
