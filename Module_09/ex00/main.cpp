/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 11:11:17 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/29 16:09:03 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// ! BTC Exchange

/*
	Use Array for random access, and fixed size at runtime.
	Sort dates.
	
	Use three pointers for Binary Search:
		u = upper
		i = midpoint index i = (l + u) / 2
		l = lower

	1. File class for open & read.

	2. Date struct with:	
		a) == opperator.
		b) format checker.

	3. Binary search.
*/

// TODO
/*
	Invalid input:
		✅ Invalid date
		✅ Empty row
		✅ Empty file
		✅ File permissions

	Classes:
		✅ Free in copy constructor

	Look-up
		✅ Date not found -> Use next lowest

	Makefile
		1. Dependency on .tpp
		2. Dependency on .hpp
*/

#include "include/colors.hpp"
#include "include/BitcoinExchange.hpp"

int	main(int argc, char **argv) {

	// Check args
	if (argc != 2) {
		std::cerr << C_RED << "Invalid argument count" << std::endl;
		return (0);
	}
	
	// Make a file
	auto parserFunction = [](std::istream& in) {
		return (parseDataFile<ARRAY_LENGTH>(in));
	};
	File<std::array<RateEntity, ARRAY_LENGTH>> inputFile(RATE_DATA_FILE_PATH, parserFunction);

	// Convert
	std::string			inputFileName = argv[1];
	BitcoinExchange		exchange = BitcoinExchange(inputFile);
	
	exchange.convertRates(exchange.parseInput(inputFileName));
}
