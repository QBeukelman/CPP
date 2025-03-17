/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 21:22:00 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 22:15:00 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void) {
	std::cout 
		<< C_BLUE
		<< "DEBUG: "
		<< RESET_COLOR
		<< DEBUG_MESSAGE
		<< std::endl; 
}

void	Harl::info(void) {
	std::cout 
	<< C_BLUE
	<< "INFO: "
	<< RESET_COLOR
	<< INFO_MESSAGE
	<< std::endl; 
}

void	Harl::warning(void) {
	std::cout 
	<< C_BLUE
	<< "WARNING: "
	<< RESET_COLOR
	<< WARNING_MESSAGE
	<< std::endl; 
}

void	Harl::error(void) {
	std::cout 
	<< C_BLUE
	<< "ERROR: "
	<< RESET_COLOR
	<< ERROR_MESSAGE
	<< std::endl; 
}

void	Harl::complain(std::string level) {
	std::map<std::string, void (Harl::*)()>::iterator method = methodMap.find(level);
	if (method != methodMap.end()) {
		(this->*method->second)();
	} else {
		std::cout
			<< C_RED
			<< "Method not found.\n"
			<< RESET_COLOR;
	}
}
