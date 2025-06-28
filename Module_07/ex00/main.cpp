/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/27 10:17:09 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/28 12:12:31 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/comparator.hpp"
#include "include/writer.hpp"

#include <iostream>

template <typename T> void swap(T& x, T& y) {
	T	temp;
	
	temp = x;
	x = y;
	y = temp;
}

template <typename T> T min(T x, T y) {
	if (x < y)
		return (x);
	return (y);
}

template <typename T> T max(T x, T y) {
	if (x > y)
		return (x);
	return (y);
}

int	main(void) {

	write_divider();
	write_title("TEST 1: Compare & Swap Integers");
	{
		int		x = 0;
		int		y = 10;
		
		std::cout
			<< "Max of x(" << x << ") and y(" << y << ") is: "
			<< C_BLUE
			<< ::max(x, y)
			<< RESET_COLOR
			<< std::endl;
		
		std::cout
			<< "Min of x(" << x << ") and y(" << y << ") is: "
			<< C_BLUE
			<< ::min(x, y)
			<< RESET_COLOR
			<< std::endl;

		::swap(x, y);
		std::cout
			<< "Swap: "
			<< "X = "
			<< C_BLUE
			<< x
			<< RESET_COLOR
			<< ", Y = "
			<< C_BLUE
			<< y
			<< RESET_COLOR
			<< std::endl;
	}

	write_divider();
	write_title("TEST 2: Compare & Swap Chars");
	{
		std::string	a = "String 1";
		std::string	b = "String 2";

		std::cout
			<< "Max of a and b is: "
			<< C_BLUE
			<< ::max(a, b)
			<< RESET_COLOR
			<< std::endl;
		
		std::cout
			<< "Min of a and b is: "
			<< C_BLUE
			<< ::min(a, b)
			<< RESET_COLOR
			<< std::endl;

		::swap(a, b);
		std::cout
			<< "Swap: "
			<< "A = "
			<< C_BLUE
			<< a
			<< RESET_COLOR
			<< ", B = "
			<< C_BLUE
			<< b
			<< RESET_COLOR
			<< std::endl;
	}
	write_divider();
}
