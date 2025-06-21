/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/21 10:16:05 by quentin       #+#    #+#                 */
/*   Updated: 2025/06/21 14:39:55 by quentin       ########   odam.nl         */
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


void	ScalarConverter::convert(const std::string& input) {
	char	charValue;
	int		intValue;
	float	floatValue;
	double	doubleValue;

	std::istringstream stream(input);

	// -----------------------------------------------------------------------------
	// Char
	if (input.size() == 1) {
		if (isdigit(input[0])) {
			try {
				int number = std::stoi(input);
				if (isprint(number) == true) {
					std::cout
						<< C_BLUE
						<< "Char: \t\t"
						<< input[0]
						<< RESET_COLOR
						<< std::endl;
				} else {
					std::cout
						<< C_RED
						<< " Char: \t\tNon displayable."
						<< RESET_COLOR
						<< std::endl;
				}
			} catch (std::exception& e) {
				std::cout << e.what();
			}
		} else {
			std::cout
				<< C_BLUE
				<< "Char: \t\t"
				<< input[0]
				<< RESET_COLOR
				<< std::endl;
		}
	} else {
		if (isValidInput(input)) {
			try {
				int number = std::stoi(input);
				if (isInCharRange(number)) {
					charValue = static_cast<char>(number);
					if (!isprint(number)) {
						std::cout
							<< C_RED
							<< "Char: \t\tNon displayable."
							<< RESET_COLOR
							<< std::endl;
					} else {
						std::cout
							<< C_BLUE
							<< "Char: \t\t" // ? Display '*' with "42"?
							<< charValue
							<< RESET_COLOR
							<< std::endl;
					}
				} else {
					std::cout
						<< C_RED
						<< "Char: \t\tImpossible (out of ascii range)."
						<< RESET_COLOR
						<< std::endl;
				}
			} catch (std::exception& e) {
				std::cout
					<< C_RED
					<< "Char: \t\tImpossible (out of ascii range)."
					<< RESET_COLOR
					<< std::endl;
			}
		} else {
			std::cout
				<< C_RED
				<< "Char: \t\tImpossible, could not be converted."
				<< RESET_COLOR
				<< std::endl;
		}
	}

	// -----------------------------------------------------------------------------
	// Int
	stream.clear();
	stream.str(input);

	if (isValidInput(input)) {
		try {
			intValue = static_cast<int>(std::stoi(input));
			std::cout
				<< C_BLUE
				<< "Int: \t\t"
				<< intValue
				<< RESET_COLOR
				<< std::endl;
		} catch (std::exception& e) {
			std::cout
				<< C_RED
				<< "Int: \t\tImpossible (out of int range)."
				<< RESET_COLOR
				<< std::endl;
		}
	} else {
		std::cout
			<< C_RED
			<< "Int: \t\tImpossible, invalid input."
			<< RESET_COLOR
			<< std::endl;
	}

	// -----------------------------------------------------------------------------
	// Float
	stream.clear();
	stream.str(input);

	if (isValidInput(input)) {
		try {
			floatValue = static_cast<float>(std::stof(input));
			std::cout
				<< C_BLUE
				<< "Float: \t\t"
				<< std::setprecision(1)
				<< std::fixed
				<< floatValue
				<< "f"
				<< RESET_COLOR
				<< std::endl;
		} catch (std::exception& e) {
			std::cout
				<< C_RED
				<< "Float: \t\tImpossible (out of float range)."
				<< RESET_COLOR
				<< std::endl;
		}
	} else {
		std::cout
			<< C_BLUE
			<< "Float: \t\t"
			<< input
			<< "f"
			<< RESET_COLOR
			<< std::endl;
	}

	// -----------------------------------------------------------------------------
	// Double
	stream.clear();
	stream.str(input);

	if (isValidInput(input)) {
		try {
			doubleValue = static_cast<double>(std::stod(input));
			std::cout
				<< C_BLUE
				<< "Double: \t"
				<< std::setprecision(1)
				<< std::fixed
				<< doubleValue
				<< RESET_COLOR
				<< std::endl;
		} catch (std::exception& e) {
			std::cout
				<< C_RED
				<< "Double: \tImpossible (out of double range)."
				<< RESET_COLOR
				<< std::endl;
		}
	} else {
		std::cout
			<< C_BLUE
			<< "Double: \t"
			<< input
			<< RESET_COLOR
			<< std::endl;
	}
}

bool	isInCharRange(const int number) {
	if (number >= 0 && number <= 127) {
		return (true);
	}
	return (false);
}

bool	isValidInput(const std::string &input) {
	(void) input;
	
	// Negatives - Skip sign and continue
	if (input[0] == '-')
		return (isValidInput(input.substr(1)));

	// Float or Double
	size_t	find;

	find = input.find('.');
	if (find && find != std::string::npos) {
		// first char '.'
		if (input[0] == '.')
			return (false);

		size_t	i = 0;
		while (i < input.size()) {
			if (!isdigit(input[i])) {
				if (input[i] == '.') {

				} else {
					return (false);
				}
			}
		}
	}
	return (true);
}
