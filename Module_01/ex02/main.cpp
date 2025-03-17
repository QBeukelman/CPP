/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:14:54 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:16:48 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../utils/utils.hpp"

#define GREETING "HI THIS IS BRAIN"

int		main(void) {
	std::string		str = GREETING;
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;
	
	write_line();

	std::cout << "Address of " << C_BLUE << "Base String:\t" << RESET_COLOR << &str << std::endl;
	std::cout << "Address of " << C_BLUE << "StringPTR:\t" << RESET_COLOR << stringPTR << std::endl;
	std::cout << "Address of " << C_BLUE << "StringREF:\t" << RESET_COLOR << &stringREF << std::endl;

	write_divider();

	std::cout << "Value of " << C_BLUE << "Base String:\t" << RESET_COLOR << str << std::endl;
	std::cout << "Value of " << C_BLUE << "StringPTR:\t" << RESET_COLOR << *stringPTR << std::endl;
	std::cout << "Value of " << C_BLUE << "StringREF:\t" << RESET_COLOR << stringREF << std::endl;

	write_line();
	return (0);
}
