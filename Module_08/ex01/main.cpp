/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/02 10:03:02 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/03 14:48:22 by quentinbeuk   ########   odam.nl         */
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
		// SpanInvalidException
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

		write_line();
		try {
			Span span = Span(3);

			span.addNumber(0);
			span.addNumber(1);
			span.addNumber(2);
			span.addNumber(3);
			std::cerr
				<< C_RED
				<< "FAILED: Span::addNumber() exceded capacitry"
				<< RESET_COLOR
				<< std::endl;
		} catch (std::exception &e) {
			std::cout
				<< C_BLUE
				<< "PASSED: Span class threw SpanOutOfBoundsException with `Span::addNumber() > 3`: \n"
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
	
		span.write_span_table();
		write_line();
		span.write_span(span.shortestSpan(), SHORTEST);
		span.write_span(span.longestSpan(), LONGEST);
	}

	write_divider();
	write_title("TEST 3: Find span for 20 random numbers");
	{
		int								range = 20;
		Span							span = Span(range);
		std::random_device				rd;
		std::mt19937					gen(rd());
		std::uniform_int_distribution<>	dist(-1000, 1000);

		for (int i = 0; i < range; i++) {
			span.addNumber(dist(gen));
		}
		
		span.write_span_table();
		write_line();
		span.write_span(span.shortestSpan(), SHORTEST);
		span.write_span(span.longestSpan(), LONGEST);
	}
	
	write_divider();
	write_title("TEST 4: Find span for 1 million random numbers");
	{
		int								range = 1000000;
		int								max_range = std::numeric_limits<int>::max();
		Span							span = Span(range);
		std::random_device				rd;
		std::mt19937					gen(rd());
		std::uniform_int_distribution<>	dist((max_range * -1), max_range);

		for (int i = 0; i < range; i++) {
			span.addNumber(dist(gen));
		}

		span.write_span(span.shortestSpan(), SHORTEST);
		span.write_span(span.longestSpan(), LONGEST);
	}
	write_divider();

	return (1);
}
