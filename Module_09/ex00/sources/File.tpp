/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   File.tpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/06 15:35:56 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/07 11:03:25 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/File.hpp"

// Constructors
// _____________________________________________________________________________
template<typename T>
File<T>::File(const std::string& fileName, std::function<ParsedResult<T>(std::istream&)> parser) {
	readData(fileName, parser);
}


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
	return ("File Exception");
}
