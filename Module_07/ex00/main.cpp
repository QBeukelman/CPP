/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/27 10:17:09 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/01 09:46:41 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sources/comparator.tpp"
#include "include/writer.hpp"

#include <iostream>

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
