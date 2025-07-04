/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   File.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 14:06:23 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/04 16:02:06 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/File.hpp"

// Constructors
// _____________________________________________________________________________

// Default constructor
template<typename Container>
File<Container>::File() {}

// ! Finish implementation
// Parameterised constructor
template<typename Container>
File<Container>::File(std::string fileName) {
	std::cout << "Parameterised constructor " << fileName << std::endl;
}

// Destructor
template<typename Container>
File<Container>::~File() {}


// Members
// _____________________________________________________________________________

template<typename Container>
void	File<Container>::read(std::string fileName) {
	std::string		line;
	std::string 	date;
	std::string 	value;
	
	// Open file
	std::ifstream file(fileName);
	if (!file.is_open()) {
		throw FileException();
	}
	
	// Clear existing data
	// this->data.clear();
	
	// Read lines
	std::getline(file, line);
	while (std::getline(file, line)) {
		size_t	commaPosition = line.find(','); // Check if comma is found?
		date = line.substr(0, commaPosition);
		value = line.substr(commaPosition + 1);
		std::cout << date << " | " << value << std::endl;
	}
	
}

// ! Validate date and value
// bool	validateDate(std::string date) {
// 	return (true);
// }

// Explicitly instantiate File with std::array<>
template class File<std::array<RateEntity, ROW_COUNT>>;

template<typename Container>
const char*	File<Container>::FileException::what() const throw() {
	return ("File Exception");
}
