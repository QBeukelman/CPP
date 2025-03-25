/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/25 00:07:42 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/25 00:43:59 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() {
	_wholeValue = 0;
}

// Destructor
Fixed::~Fixed() {
}

// Int constructor - Converts an integer to a fixed-point value
Fixed::Fixed(const int newInt) {
	this->_wholeValue = newInt << _fractionalValue;
}

// Float constructor - Converts a floating-point number to a fixed-point value
Fixed::Fixed(const float newFloat) {
	this->_wholeValue = roundf(newFloat * (1 << _fractionalValue));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
	this->_wholeValue = other._wholeValue;
}

// Copy assignment operator
Fixed	&Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		_wholeValue = other._wholeValue;
	}
	return (*this);
}

// -------------------------------------------------	Comparitor
bool	Fixed::operator>(const Fixed value) const {
	return (this->_wholeValue > value._wholeValue);
}

bool	Fixed::operator<(const Fixed value) const {
	return (this->_wholeValue < value._wholeValue);
}

bool	Fixed::operator>=(const Fixed value) const {
	return (this->_wholeValue >= value._wholeValue);
}

bool	Fixed::operator<=(const Fixed value) const {
	return (this->_wholeValue <= value._wholeValue);
}

bool	Fixed::operator==(const Fixed value) const {
	return (this->_wholeValue == value._wholeValue);
}

bool	Fixed::operator!=(const Fixed value) const {
	return (this->_wholeValue != value._wholeValue);
}


// -------------------------------------------------	Arithmetic operators
Fixed	Fixed::operator+(const Fixed value) const {
	Fixed result;
	result._wholeValue = this->_wholeValue + value._wholeValue;
	return (result);
}

Fixed	Fixed::operator-(const Fixed value) const {
	Fixed result;
	result._wholeValue = this->_wholeValue - value._wholeValue;
	return (result);
}

Fixed	Fixed::operator*(const Fixed value) const {
	Fixed result;
	result._wholeValue = (this->_wholeValue * value._wholeValue) >> _fractionalValue;
	return (result);
}

Fixed	Fixed::operator/(const Fixed value) const {
	if (value._wholeValue == 0) {
		throw std::runtime_error("Division by zero");
	}
	Fixed result;
	result._wholeValue = (this->_wholeValue << _fractionalValue) / value._wholeValue;
	return (result);
}

// -------------------------------------------------	Incriment/Decrement operators
Fixed	Fixed::operator++(void) {
	++this->_wholeValue;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);
	++this->_wholeValue;
	return (temp);
}

Fixed	Fixed::operator--(void) {
	--this->_wholeValue;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);
	--this->_wholeValue;
	return (*this);
}


// -------------------------------------------------	Static member functions
Fixed&			Fixed::min(Fixed& a, Fixed& b) {
	return ((a < b) ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return ((a < b) ? a : b);
}

Fixed&			Fixed::max(Fixed& a, Fixed& b) {
	return ((a > b) ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return ((a > b) ? a : b);
}


// -------------------------------------------------	Member functions
int		Fixed::getWholeValue(void) const {
	std::cout << "getWholeValue() member function called" << std::endl;
	return (this->_wholeValue);
}

float	Fixed::toFloat(void) const {
	return ((float)_wholeValue / (float)(1 << _fractionalValue));
}

std::ostream&	operator<<(std::ostream& out, const Fixed& value) {
	out << value.toFloat();
	return (out);
}
