/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 11:25:12 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/10 16:46:47 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// ! Merge Insert Sort (Ford-Johnson)
// TODO: How to handle duplicates?
/*
	At worst:		O(n log n).
	Linked list:	It does not rely on random access to elements.
					With two sorted lists, the lowest element will always be
					on the top of one of the two stacks.
*/

#include "include/PmergeMe.hpp"
#include "include/PmergeMeList.hpp"
#include "include/writer.hpp"

#include <chrono>
#include <iomanip>

static bool		isValidArg(std::string arg) {
	for (const auto& c : arg) {
		if (std::isdigit(c) == false)
			return (false);
	}
	return (true);
}

static void		writeTime(double seconds) {
	std::cout
		<< C_BLUE
		<< std::fixed << std::setprecision(8)
		<< std::setw(12) << std::setfill('0')
		<< seconds << " ns"
		<< RESET_COLOR
		<< std::endl;
}

static void		evaluateSequence(std::vector<int> sequence) {
	PmergeMe		sorter;

	auto t1 = std::chrono::high_resolution_clock::now();
	sorter.sort(sequence);
	auto t2 = std::chrono::high_resolution_clock::now();

	auto	duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
	double	seconds = duration_ns / 1e9;
	
	sorter.printContainer("Vec", sequence);
	
	if (sorter.isSorted(sequence)) {
		std::cout << C_GREEN << "Sort OK! " << RESET_COLOR; writeTime(seconds);
	} else
		std::cerr << C_RED << "Sort Failed!" << RESET_COLOR << std::endl;
}

static void		evaluateSequence(std::list<int> sequence) {
	PmergeMeList		sorter;

	auto t1 = std::chrono::high_resolution_clock::now();
	sorter.sort(sequence);
	auto t2 = std::chrono::high_resolution_clock::now();

	auto	duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
	double	seconds = duration_ns / 1e9;

	sorter.printContainer("List", sequence);
	
	if (sorter.isSorted(sequence)) {
		std::cout << C_GREEN << "Sort OK! " << RESET_COLOR; writeTime(seconds);
	} else
		std::cerr << C_RED << "Sort Failed!" << RESET_COLOR << std::endl;
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
	std::vector<int>	inputsVector;
	std::list<int>		inputsList;
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
			return (0);
		}
		inputsVector.push_back(std::stoi(argv[i]));
		inputsList.push_back(std::stoi(argv[i]));
	}

	write_divider();
	PmergeMe().printContainer("Input", inputsVector);
	write_divider();
	evaluateSequence(inputsVector);
	write_divider();
	evaluateSequence(inputsList);
	write_divider();
	
	return (1);
}
