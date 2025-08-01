/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:07:42 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/12 12:17:04 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Default constructor
Fixed::Fixed() {
	this->_wholeValue = 0;
}

// Destructor
Fixed::~Fixed() {}

// Int constructor - Converts an integer to a fixed-point value
Fixed::Fixed(const int newInt) {
	this->_wholeValue = newInt << this->_fractionalValue;
}

// Float constructor - Converts a floating-point number to a fixed-point value
Fixed::Fixed(const float newFloat) {
	this->_wholeValue = roundf(newFloat * (1 << this->_fractionalValue));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
	*this = other;
}

// Copy assignment operator
Fixed	&Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->_wholeValue = other._wholeValue;
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
	Fixed	result;

	result._wholeValue = this->_wholeValue + value._wholeValue;
	return (result);
}

Fixed	Fixed::operator-(const Fixed value) const {
	Fixed	result;

	result._wholeValue = this->_wholeValue - value._wholeValue;
	return (result);
}

Fixed	Fixed::operator*(const Fixed value) const {
	Fixed	result;
	int64_t	wideResult;

	// Promote to 64-bit before shifting
	wideResult = static_cast<int64_t>(this->_wholeValue) * value._wholeValue;
	wideResult >>= this->_fractionalValue;

	result._wholeValue = static_cast<int>(wideResult);
	return (result);
}

Fixed	Fixed::operator/(const Fixed value) const {
	Fixed	result;
	int64_t	numerator;
	int64_t	wideResult;

	if (value._wholeValue == 0) {
		throw std::runtime_error("Division by zero");
	}

	// Promote to 64-bit before shifting
	numerator = static_cast<int64_t>(this->_wholeValue) << this->_fractionalValue;
	wideResult = numerator / value._wholeValue;
	result._wholeValue = static_cast<int>(wideResult);
	
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
	std::cout << "getWholeValue() member function called." << std::endl;
	return (this->_wholeValue);
}

float	Fixed::toFloat(void) const {
	return ((float)_wholeValue / (float)(1 << this->_fractionalValue));
}

std::ostream&	operator<<(std::ostream& out, const Fixed& value) {
	out << value.toFloat();
	return (out);
}
