/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:43:55 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/08/04 14:51:57 by qbeukelm         ###   ########.fr       */
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
		RPN();
		RPN(std::string expression);
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);
		~RPN();

		bool			isValid(std::string expression);
		long long		evaluate();

		class InvalidExpressionException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
