/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:24:28 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/07/28 09:04:46 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources/iter.tpp"
#include "include/writer.hpp"

void	printInt(int x) {
	std::cout
		<< "Value: "
		<< C_BLUE
		<< x
		<< RESET_COLOR
		<< std::endl;
}

/*
	Generic template function (Instantiated in main).
	
	Each time the template is used with a different type,
	the compiler instantiates a separate version:

	- `void templatePrintFunc<int>(int x)`
	- `void templatePrintFunc<std::string>(std::string x)`
*/
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
