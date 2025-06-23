/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/21 10:16:05 by quentin       #+#    #+#                 */
/*   Updated: 2025/06/23 16:33:03 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other) {}
	return (*this);
}

ScalarConverter::~ScalarConverter() {}


void printResult(const std::string& label, const std::string& value, bool error = false) {
	std::cout
		<< (error ? C_RED : C_BLUE)
		<< label << ":\t\t" << value
		<< RESET_COLOR
		<< std::endl;
}

void	ScalarConverter::convert(const std::string& input) {
	std::istringstream stream(input);

	// -------------------- CHAR --------------------
	if (input.length() == 1 && !std::isdigit(input[0])) {
		printResult("Char", std::string(1, input[0]));
	} else {
		try {
			int number = std::stoi(input);
			if (number >= 0 && number <= 127) {
				char c = static_cast<char>(number);
				if (std::isprint(c))
					printResult("Char", std::string(1, c));
				else
					printResult("Char", "Non displayable.", true);
			} else {
				printResult("Char", "Impossible (out of ASCII range).", true);
			}
		} catch (...) {
			printResult("Char", "Impossible, could not be converted.", true);
		}
	}

	// -------------------- INT --------------------
	try {
		int i = std::stoi(input);
		printResult("Int", std::to_string(i));
	} catch (...) {
		printResult("Int", "Impossible (out of int range).", true);
	}

	// -------------------- FLOAT --------------------
	try {
		float f = std::stof(input);
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(1) << f << 'f';
		printResult("Float", oss.str());
	} catch (...) {
		printResult("Float", "Impossible (out of float range).", true);
	}

	// -------------------- DOUBLE --------------------
	try {
		double d = std::stod(input);
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(1) << d;
		printResult("Double", oss.str());
	} catch (...) {
		printResult("Double", "Impossible (out of double range).", true);
	}
}

bool	isInCharRange(const int number) {
	if (number >= 0 && number <= 127) {
		return (true);
	}
	return (false);
}

bool	isValidInput(const std::string &input) {
	// Integer (42, -5)
	std::regex intRegex(R"(^[+-]?\d+$)");
	// Float (3.14f)
	std::regex floatRegex(R"(^[+-]?\d+\.\d+f$)");
	// Double (4.2)
	std::regex doubleRegex(R"(^[+-]?\d+\.\d+$)");
	// Special float literals: nanf, inff
	std::regex floatSpecialRegex(R"(^[+-]?(nanf|inff)$)", std::regex_constants::icase);
	// Special double literals: nan, inf
	std::regex doubleSpecialRegex(R"(^[+-]?(nan|inf)$)", std::regex_constants::icase);
	
	return (std::regex_match(input, intRegex) ||
			std::regex_match(input, floatRegex) ||
			std::regex_match(input, doubleRegex) ||
			std::regex_match(input, floatSpecialRegex) ||
			std::regex_match(input, doubleSpecialRegex));
}
