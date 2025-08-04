/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:35:56 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/08/04 14:45:33 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/File.hpp"
#include "../include/colors.hpp"

// Constructors
// _____________________________________________________________________________
template<typename T>
File<T>::File() : data(std::array<RateEntity, ARRAY_LENGTH>()), count(0) {}

template<typename T>
File<T>::File(const std::string& fileName, std::function<ParsedResult<T>(std::istream&)> parser) {
	try {
		readData(fileName, parser);
	} catch (FileException& e) {
		std::cerr
			<< C_RED
			<< e.what()
			<< RESET_COLOR
			<< std::endl;
	}
}

template<typename T>
File<T>::File(const File<T>& other) : data(other.data), count(other.count) {}

template<typename T>
File<T>&	File<T>::operator=(const File<T>& other) {
	if (this != &other) {
		this->data = other.data;
		this->count = other.count;	
	}
	return (*this);
}

template<typename T>
File<T>::~File() {}


// Members
// _____________________________________________________________________________
template<typename T>
void	File<T>::readData(const std::string& fileName, std::function<ParsedResult<T>(std::istream&)> parser) {
	std::ifstream	in(fileName);
	
	if (!in.is_open()) {
		throw FileException();
	}
	auto result = parser(in);
	this->data = result.data;
	this->count = result.count;
}

template <typename T>
const T&	File<T>::getData() const {
	return (this->data);
}

template <typename T>
size_t	File<T>::getCount() const {
	return (this->count);
}

template<typename T>
const char*	File<T>::FileException::what() const throw() {
	return ("FILE EXCEPTION: Could not open file");
}
