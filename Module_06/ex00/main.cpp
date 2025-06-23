/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/21 10:35:34 by quentin       #+#    #+#                 */
/*   Updated: 2025/06/23 16:21:55 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScalarConverter.hpp"
#include "include/helpers.hpp"

/*
	"0"
	"nan"
	"42.0f"
	"a"
	"4.2"
	"234456778994453355354576535526738582048639573" -> Max int/float
	"66"
	"12.h"
	"12h"
	"12.12h"
	"12.12"
	"12.12f"
	"12.f"
	"12.0h"
	"12.12hf"
	"12.12fh"
	"12."
	".12"
	"a2.12"
	"-4.2"
	"-4.20f"
	"-234456778994453355354576"
	"-66"
*/

int main() {

	write_divider();
	write_title("TEST 1: Pseudo-literals");
	{
		ScalarConverter::convert("nan");
		ScalarConverter::convert("+nanf");
		ScalarConverter::convert("-nan");
		write_line();
		
		ScalarConverter::convert("inf");
		ScalarConverter::convert("+inff");
		ScalarConverter::convert("-inf");
	}
	write_divider();

	write_title("TEST 2: Simple Conversions");
	{
		ScalarConverter::convert("a");
		ScalarConverter::convert("0");
		ScalarConverter::convert("42");
		ScalarConverter::convert("4.2");
		ScalarConverter::convert("88.0f");
		write_line();
	}
	write_divider();

	write_title("TEST 3: Error Checks");
	{
		ScalarConverter::convert("a.a");
		ScalarConverter::convert("42.");
		ScalarConverter::convert("42.a");
		ScalarConverter::convert("a.42f");
		ScalarConverter::convert("--42");
		write_line();
	}
	write_divider();
}
