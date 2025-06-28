/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/27 11:24:28 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/28 12:52:45 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/iter.hpp"
#include "include/writer.hpp"

template <typename T, typename Func> void iter(T* arr, size_t size, Func func) {
	for (size_t i = 0; i < size; i++) {
		func(arr[i]);
	}
}

void	printInt(int x) {
	std::cout
		<< "Value: "
		<< C_BLUE
		<< x
		<< RESET_COLOR
		<< std::endl;
}

// Instantiated template function
template <typename T> void templatePrintFunc(T x) {
	std::cout
		<< "Value: "
		<< C_BLUE
		<< x
		<< RESET_COLOR
		<< std::endl;
}

// Const reference
void	printConstRef(const int& x) {
	std::cout
		<< "Value: "
		<< C_BLUE
		<< x
		<< RESET_COLOR
		<< std::endl;
}

// Non-const reference
void	printDoubleValue(int& x) {
	std::cout
		<< "Value: "
		<< C_BLUE
		<< (x *= 2)
		<< RESET_COLOR
		<< std::endl;
}

int	main(void) {
	int		nums[] = {10, 20, 30};
	size_t	size = 3;

	write_divider();
	write_title("TEST 1: Typed function parameter");
	{
		iter(nums, size, printInt);
	}

	write_divider();
	write_title("TEST 2: Instantiated template function");
	{
		iter(nums, size, templatePrintFunc<int>);
	}
	
	write_divider();
	write_title("TEST 3: Const reference function");
	{
		iter(nums, size, printConstRef);
	}
	
	write_divider();
	write_title("TEST 4: Non-const reference function");
	{
		iter(nums, size, printDoubleValue);
	}
	write_divider();
}
