/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:14:54 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/11 12:10:43 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define C_YELLOW "\033[1;33m"
#define C_RED "\x1B[1;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define RESET_COLOR "\033[0m"

#define GREETING "HI THIS IS BRAIN"

void		write_line(void) { std::cout << std::endl; }
void		write_divider(void) { std::cout << std::endl << "---------------------\n\n"; }

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
