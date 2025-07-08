/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 11:24:46 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/08 14:46:43 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Reverse Polish Notation

/*
	An operator applies to the two immediately preceding operands.
	
	a + b * c		-> a b c + *
	(a + b) * c		-> a b + c * 
	
	1. If operand, push to stack.
	2. If operator, pop two operands and perform operation, push intermediate answer back.

	./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	42

	./RPN "7 7 * 7 -"
	42

	./RPN "1 2 * 2 / 2 * 2 4 - +"
	0
	
	./RPN "(1 + 1)"
	Error
*/

#include "include/RPN.hpp"

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr
			<< C_RED
			<< "Invalid argument count."
			<< RESET_COLOR
			<< std::endl;
		return (0);
	}
	std::string		expression = argv[1];
	
	try {
		RPN rpn = RPN(expression);
		std::cout << rpn.evaluate() << std::endl;
	} catch (std::exception& e) {
		std::cerr << C_RED << "Caught Exception: " << e.what() << RESET_COLOR << std::endl;
		return (0);
	}
	return (1);
}
