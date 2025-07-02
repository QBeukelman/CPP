/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/02 10:03:02 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/02 13:34:12 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <random>

#include "include/Span.hpp"
#include "include/writer.hpp"

int	main(void) {

	write_divider();
	write_title("TEST 1: Check exceptions");
	{
		// ! Test out of bounds exception
		try {
			Span span = Span();
			span.longestSpan();
			std::cerr
				<< C_RED
				<< "FAILED: "
				<< "Span was used with `n < 2`."
				<< RESET_COLOR
				<< std::endl;
		} catch (std::exception &e) {
			std::cout
				<< C_BLUE
				<< "PASSED: Span class threw SpanInvalidException with `n < 2`: \n"
				<< e.what()
				<< RESET_COLOR
				<< std::endl;
		}
	}

	write_divider();
	write_title("TEST 2: Find span for 5 orderd numbers");
	{
		Span		span = Span(5);
	
		span.addNumber(0);
		span.addNumber(1);
		span.addNumber(2);
		span.addNumber(3);
		span.addNumber(4);
	
		span.write_span(span.shortestSpan(), SHORTEST);
		span.write_span(span.longestSpan(), LONGEST);
	}

	write_divider();
	write_title("TEST 3: Find span for 100 random numbers");
	{
		Span							span = Span(100);
		std::random_device				rd;
		std::mt19937					gen(rd());
		std::uniform_int_distribution<>	dist(-1000, 1000);

		for (int i = 0; i < 100; i++) {
			span.addNumber(dist(gen));
		}
		
		span.write_span(span.shortestSpan(), SHORTEST);
		span.write_span(span.longestSpan(), LONGEST);
	}
	write_divider();
		
	return (1);
}
