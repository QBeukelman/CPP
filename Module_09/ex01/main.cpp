/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:24:46 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/08/04 09:35:20 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reverse Polish Notation

/*
	An operator applies to the two immediately preceding operands.
	
	a + b * c		-> a b c + *
	(a + b) * c		-> a b + c * 
	
	1. If operand, push to stack.
	2. If operator, pop two operands and perform operation, push intermediate answer back.

	
	! Valid test cases
	
	./RPN "3 4 +"
	# 7

	./RPN "5 1 2 + 4 * + 3 -"
	# 14   (Equivalent to: 5 + ((1 + 2) * 4) - 3)

	./RPN "10 2 8 * + 3 -"
	# 23   (Equivalent to: 10 + 2 * 8 - 3)

	./RPN "6 2 / 3 -"
	# 0   (Equivalent to: (6 / 2) - 3)

	./RPN "4 2 5 * + 1 3 2 * + /"
	# 2   (Equivalent to: (4 + 2 * 5) / (1 + 3 * 2))

	! Invalid test cases
	./RPN "+"
	# Error  (Not enough operands)

	./RPN "1 +"
	# Error  (Operator before enough operands)

	./RPN "2 3"
	# Error  (Missing operator)

	./RPN "2 3 &"
	# Error  (Invalid character/operator)

	./RPN "4 0 /"
	# Error  (Division by zero)

	./RPN "10 5 - -"
	# Error  (Too few operands for second minus)

	./RPN "(2 3 +)"
	# Error  (Parentheses are not allowed)

	./RPN ""
	# Error  (Empty input)
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
