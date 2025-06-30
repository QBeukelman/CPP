/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.tpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/28 15:14:49 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/30 17:49:25 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"

// Default constructor
template <class T>
Array<T>::Array() : data(nullptr), arraySize(0) {}

// Parameterized constructor
template <class T>
Array<T>::Array(unsigned int n) : arraySize(n) {
	this->data = new T[n]; // Allocate memory

	for (unsigned int i = 0; i < n; i++) {
		data[i] = T(); // Default-initialize each element
	}
}

// Copy constructor
template <class T>
Array<T>::Array(const Array& other) : arraySize(other.arraySize) {
	this->data = new T[other.arraySize];
	
	for (unsigned int i = 0; i < other.arraySize; i++) {
		data[i] = other.data[i]; // Element-wise copy
	}
}

// Copy assignment operator
template <class T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this == &other) {
		return (*this); // Self-assignment check
	}

	delete[] data; // Free old memory

	this->arraySize = other.arraySize;
	this->data = new T[other.arraySize];
	for (unsigned int i = 0; i < other.arraySize; i++) {
		data[i] = other.data[i]; // Element-wise copy
	}
	return (*this);
}

// Destructor
template <class T>
Array<T>::~Array() {
	delete[] data;
}

// Non-const [] operator
template<class T>
T&	Array<T>::operator[](unsigned int index) {
	if (index >= this->arraySize) {
		throw OutOfBoundsException();
	}
	return (data[index]);
}

// Const [] operator
template <class T>
const T&	Array<T>::operator[](unsigned int index) const {
	if (index >= this->arraySize) {
		throw OutOfBoundsException();
	}
	return (data[index]);
}

template <class T>
unsigned int	Array<T>::size(void) const {
	return (this->arraySize);
}

template <class T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
	return ("EXCEPTION: Array index is out of bounds");
}
