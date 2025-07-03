/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutatedStack.tpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/03 11:19:43 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/03 13:39:20 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "../include/MutatedStack.hpp"

// Constructors
// _____________________________________________________________________________

// Default constructor
template<typename T>
MutatedStack<T>::MutatedStack() {

}

// Copy constructor
template <typename T>
MutatedStack<T>::MutatedStack(const MutatedStack& other) {
	(void)other;
}

// Copy assignment operator
template <typename T>
MutatedStack<T>&	MutatedStack<T>::operator=(const MutatedStack& other) {
	(void)other;
}

// Destructor
template <typename T>
MutatedStack<T>::~MutatedStack() {

}


// Members
// _____________________________________________________________________________

template <typename T>
typename MutatedStack<T>::iterator MutatedStack<T>::begin() {
	return (this->c.begin());
}

template <typename T>
typename MutatedStack<T>::iterator MutatedStack<T>::end() {
	return (this->c.end());
}

template <typename T>
typename MutatedStack<T>::const_iterator MutatedStack<T>::begin() const {
	return (this->c.begin());
}

template <typename T>
typename MutatedStack<T>::const_iterator MutatedStack<T>::end() const {
	return (this->c.end());
}

template <typename T>
typename MutatedStack<T>::const_iterator MutatedStack<T>::cbegin() const {
	return (this->c.cbegin());
}

template <typename T>
typename MutatedStack<T>::const_iterator MutatedStack<T>::cend() const {
	return (this->c.cend());
}
