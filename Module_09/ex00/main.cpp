/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 11:11:17 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/08/05 10:00:48 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
	----------------------------------------------------------------------------
	🔧 Example Use Case:
	----------------------------------------------------------------------------

	Input file line:
		2014-01-15 | 3.5

	CSV file contains:
		...
		2014-01-14, 850.50
		2014-01-15, 860.00
		2014-01-16, 870.25
		...

	Binary search finds 2014-01-15 with rate 860.00
	Output:
		2014-01-15 => 3.5 = 3010.00
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
