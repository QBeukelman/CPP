/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 11:11:17 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/06 20:53:49 by quentinbeuk   ########   odam.nl         */
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

#include "include/colors.hpp"
#include "include/BitcoinExchange.hpp"

int	main(int argc, char **argv) {

	// Check args
	// TODO: Input for look-up
	if (argc != 2) {
		std::cerr << C_RED << "Invalid argument count" << std::endl;
		return (0);
	}
	
	// Make a file
	auto parser = [](std::istream& in) {
		return (parseDataFile<ARRAY_LENGTH>(in));
	};
	File<std::array<RateEntity, ARRAY_LENGTH>> file(RATE_DATA_FILE_PATH, parser);
	// auto rates = file.getData();
	
	// for (const auto& rate : rates) {
	// 	std::cout	<< rate.date.day << "-"
	// 	<< rate.date.month << "-"
	// 	<< rate.date.year << "\t = "
	// 	<< rate.value
	// 	<< std::endl;
	// }
	
	// Convert
	std::string			inputFile = argv[1];
	BitcoinExchange		exchange = BitcoinExchange(file);
	exchange.convertRates(exchange.parseInput(inputFile));
}
