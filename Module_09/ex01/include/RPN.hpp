/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 08:43:55 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/08 14:01:19 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include "colors.hpp"

enum TokenType {
	INVALID,
	OPERAND,
	OPERATOR
};

class RPN {
	private:
		std::string			expression;

	public:
		RPN() = delete;
		RPN(std::string expression);

		bool			isValid(std::string expression);
		long long		evaluate();

		class InvalidExpressionException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
