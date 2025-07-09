/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 11:25:12 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/09 16:35:51 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// ! Merge Insert Sort (Ford-Johnson)
// TODO: ./PmergeMe $(for i in {1..10}; do echo $((RANDOM % 1000 + 1)); done)

/*
	At worst:		O(n log n).
	Linked list:	It does not rely on random access to elements.
					With two sorted lists, the lowest element will always be
					on the top of one of the two stacks.
*/

#include "include/PmergeMe.hpp"

static bool		isValidArg(std::string arg) {
	for (const auto& c : arg) {
		if (std::isdigit(c) == false)
			return (false);
	}
	return (true);
}

int main(int argc, char** argv) {

	// Validate input count
	if (argc < 2) {
		std::cerr
			<< C_RED
			<< "Error: Invalid input. Usage: ./PmergeMe <int1> <int2> ... <intN>"
			<< RESET_COLOR << std::endl;
		return (0);
	}

	// Validate and parse inputs
	std::vector<int>	inputs;
	for (int i = 1; i < argc; i++) {
		std::string		arg = argv[i];
		if (isValidArg(arg) == false) {
			std::cerr
				<< C_RED
				<< "Error: Invalid Input '"
				<< arg
				<< "'. Only positive integers"
				<< RESET_COLOR
				<< std::endl;
		}
		inputs.push_back(std::stoi(argv[i]));
	}

	// Sort inputs
	PmergeMe	sorter;
	sorter.sort(inputs);

	return (1);
}
