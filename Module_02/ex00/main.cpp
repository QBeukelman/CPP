/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/24 21:45:30 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/24 22:16:24 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {

	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;

	std::cout << a.getWholeValue() << std::endl;
	std::cout << b.getWholeValue() << std::endl;
	std::cout << c.getWholeValue() << std::endl;
	
	return (0);
}
