/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/28 15:12:39 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/01 09:48:59 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
	! Tip: Try to compile int * a = new int(); then display *a.
*/
#include <iostream>
#include "include/writer.hpp"
#include "sources/Array.tpp"

#define MAX_VAL 10

int main(int, char**)
{
	Array<int>	numbers(MAX_VAL);
	int*		mirror = new int[MAX_VAL];
	
	srand(time(NULL));

	write_divider();
	write_title("TEST 1: Default Constructor (empty array)");
	{
		Array<int>	empty;

		if (empty.size() == 0) {
			std::cout
				<< C_BLUE
				<< "PASSES: Array size is: "
				<< empty.size()
				<< RESET_COLOR
				<< std::endl;
		} else {
			std::cerr
				<< C_RED
				<< "FAILED: Array size is: "
				<< empty.size()
				<< ", but should be 0."
				<< RESET_COLOR
				<< std::endl;
		}

		try {
			empty[0] = 42;
			std::cerr
				<< C_RED
				<< "FAILED: No exception was thrown when accessing empty array."
				<< RESET_COLOR
				<< std::endl;
		} catch (std::exception& e) {
			std::cout
				<< C_BLUE
				<< "PASSES: Exception caught when accessing element in empty array: \n"
				<< C_RED
				<< e.what()
				<< RESET_COLOR
				<< std::endl;
		}
	}

	write_divider();
	write_title("TEST 2: Create & Match Arrays");
	{
		for (int i = 0; i < MAX_VAL; i++) {
			const int value = rand();
	
			numbers[i] = value;
			mirror[i] = value;
		}
	
		for (int i = 0; i < MAX_VAL; i++) {
			if (mirror[i] == numbers[i]) {
				std::cout
					<< "Numbers matched mirror: "
					<< C_BLUE
					<< numbers[i]
					<< RESET_COLOR
					<< std::endl;
			} else {
				std::cerr
					<< C_RED
					<< "Didn't save the same value!"
					<< RESET_COLOR
					<< std::endl;
				return (1);
			}
		}
	}

	write_divider();
	write_title("TEST 3: Test Copy/Assignment Constructors");
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	
		tmp[0] = 999;
		test[1] = 888;

		if (numbers[0] == 999 || numbers[1] == 888) {
			std::cerr
				<< C_RED
				<< "FAILED: original array was modified."
				<< RESET_COLOR
				<< std::endl;
		} else {
			std::cout
				<< C_BLUE
				<< "PASSED: original array is intact."
				<< RESET_COLOR
				<< std::endl;
		}
	}
	
	write_divider();
	write_title("TEST 4: Out Of Bounds Exception");
	{
		try {
			numbers[-2] = 0;
		} catch(const std::exception& e) {
			std::cerr
				<< C_RED
				<< e.what()
				<< RESET_COLOR << '\n';
		}
	
		try {
			numbers[MAX_VAL] = 0;
		} catch(const std::exception& e) {
				std::cerr
				<< C_RED
				<< e.what()
				<< RESET_COLOR << '\n';
		}
	}
	write_divider();

	delete [] mirror;
}
