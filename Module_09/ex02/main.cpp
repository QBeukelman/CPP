/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 11:25:12 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/08/05 10:12:59 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
	----------------------------------------------------------------------------
	🔧 Merge Insert Sort (Ford-Johnson) with Jacobsthal Sequence Optimization
	----------------------------------------------------------------------------

	0. Input Parsing

		The program takes a sequence of positive integers (e.g. from command-line 
		arguments) and stores them in both a `std::vector` and a `std::deque`.

	1. Pairing and Splitting

		The sequence is grouped into pairs. For each pair:
		- The larger value is added to the `maxima` list.
		- The smaller value is added to the `minima` list.

	2. Recursive Sorting*

		The `maxima` list is recursively sorted using the same algorithm.

	3. Insertion Phase

		Elements from the `minima` list are inserted into the sorted `maxima` list using:
			- Binary search for fast insertion position lookup (`O(log n)`).
			- Jacobsthal sequence to minimize the number of comparisons.
*/

#include "include/PmergeMe.hpp"
#include "include/PmergeMeDeque.hpp"
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

static void		evaluateSequence(std::deque<int> sequence) {
	PmergeMeDeque		sorter;

	auto t1 = std::chrono::high_resolution_clock::now();
	sorter.sort(sequence);
	auto t2 = std::chrono::high_resolution_clock::now();

	auto	duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
	double	seconds = duration_ns / 1e9;

	sorter.printContainer("Deque", sequence);
	
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
	std::deque<int>		inputsDeque;
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
		inputsDeque.push_back(std::stoi(argv[i]));
	}

	write_divider();
	PmergeMe().printContainer("Input", inputsVector);
	write_divider();
	evaluateSequence(inputsVector);
	write_divider();
	evaluateSequence(inputsDeque);
	write_divider();

	return (1);
}
