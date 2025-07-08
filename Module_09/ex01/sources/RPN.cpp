/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 08:43:50 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/08 14:46:07 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

// Constructors
// _____________________________________________________________________________

RPN::RPN(std::string expression) {
	if (isValid(expression) == false)
		throw InvalidExpressionException();
	this->expression = expression;
}


// Static Members
// _____________________________________________________________________________

TokenType	tokenType(std::string token) {
	// Is valid number
	if (token.length() == 1 && std::isdigit(token[0]))
		return (OPERAND);
	if (token.length() == 2 && token[0] == '-' && std::isdigit(token[1]))
		return (OPERAND);

	// Is valid operator
	if (token.length() == 1) {
		if (token[0] == '+' || token[0] == '-'
			|| token[0] == '*' || token[0] == '/')
			return (OPERATOR);
	}
	return (INVALID);
}

int		applyArithmetic(char op, int a, int b) {
	switch (op) {
		case '+': return (a + b);
		case '-': return (b - a);
		case '*': return (a * b);
		case '/':
			if (b == 0) throw std::runtime_error("Divistion by 0");
			return (b / a);
		default:
			throw std::runtime_error("Unkown operator");
	}
}



// Public Members
// _____________________________________________________________________________
bool		RPN::isValid(std::string expression) {
	std::istringstream	iss(expression);
	std::string			token;

	int					operandCount = 0;
	int					operatorCount = 0;

	while (iss >> token) {
		TokenType	type = tokenType(token);

		switch (type) {
			case OPERAND: {
				operandCount++;
				break ;
			}
			case OPERATOR: {
				operatorCount++;
				if (operandCount < 2)
					return (false);
				operandCount--;
				break ;
			}
			default: return (false);
		}
	}
	if (operatorCount < 1)
		return (false);
	if (operandCount != 1)
		return (false);
	return (true);
}

long long	RPN::evaluate() {
	std::istringstream	iss(expression);
	std::string			token;
	std::stack<int>		stack;
	
	while (iss >> token) {
		if (tokenType(token) == OPERAND) {
			stack.push(std::stoi(token));
		}
		
		if (tokenType(token) == OPERATOR) {
			char	op = token[0];
			int		a = stack.top(); stack.pop();
			int		b = stack.top(); stack.pop();

			stack.push(applyArithmetic(op, a, b));
		}

		if (tokenType(token) == INVALID)
			throw InvalidExpressionException();
	}

	return (stack.top());
}

const char*	RPN::InvalidExpressionException::what() const throw() {
	return ("The given expression is not valid.");
}
