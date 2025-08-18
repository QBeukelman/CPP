/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 08:43:50 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/08/18 14:44:44 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

// Constructors
// _____________________________________________________________________________
RPN::RPN() : expression("") {}

RPN::RPN(std::string expression) {
	if (isValid(expression) == false)
		throw InvalidExpressionException();
	this->expression = expression;
}

RPN::RPN(const RPN& other) : expression(other.expression) {}

RPN&	RPN::operator=(const RPN& other) {
	if (this != &other) {
		this->expression = other.expression;
	}
	return (*this);
}

RPN::~RPN() {}


// Static Members
// _____________________________________________________________________________
bool isInteger(const std::string& s) {
	if (s.empty())
		return (false);
	size_t start = (s[0] == '-' || s[0] == '+') ? 1 : 0;
	if (start == s.size())
		return (false); // string was just '+' or '-'
	for (size_t i = start; i < s.size(); ++i) {
		if (!isdigit(s[i]))
			return (false);
	}
	return (true);
}

TokenType	tokenType(const std::string& token) {
	if (isInteger(token))
		return (OPERAND);
	if (token == "+" || token == "-" || token == "*" || token == "/")
		return (OPERATOR);
	return (INVALID);
}

int		applyArithmetic(char op, int a, int b) {
	switch (op) {
		case '+': return (a + b);
		case '-': return (b - a);
		case '*': return (a * b);
		case '/':
			if (a == 0) throw std::runtime_error("Divistion by 0");
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
