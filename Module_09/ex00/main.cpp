/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 11:11:17 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/04 15:51:04 by quentinbeuk   ########   odam.nl         */
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
#include "include/File.hpp"
#include "models/RateEntity.hpp"

int	main(int argc, char **argv) {

	// Check args
	if (argc != 2) {
		std::cerr << C_RED << "Invalid argument count" << std::endl;
		return (0);
	}
	std::cout << "Filename: " << argv[1] << std::endl;

	// Make a file
	File<std::array<RateEntity, ROW_COUNT>> file;
	file.read(argv[1]);
}
