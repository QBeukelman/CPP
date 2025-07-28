/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:41:40 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/07/28 11:26:24 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include "../include/writer.hpp"

// Constructors
// _____________________________________________________________________________

// Default constructor
Span::Span() : n(0), numbers() {}

// Parameterized constructor
Span::Span(unsigned int n) : n(n) {
	numbers.reserve(n);
}

// Copy constructor
Span::Span(const Span& other) : n(other.n), numbers(other.numbers) {}

// Copy assignment operator
Span&	Span::operator=(const Span& other) {
	if (this != &other) {
		this->n = other.n;
		this->numbers = other.numbers;
	}
	return (*this);
}

// Destructor
Span::~Span() {}


// Members
// _____________________________________________________________________________
void	Span::addNumber(int number) {
	if (this->n < 2)
		throw SpanInvalidException();
	if (this->numbers.size() >= this->n) 
		throw SpanOutOfBoundsException();
	this->numbers.push_back(number);
}

/*
	Sort elements in list, then find shortest neighboring elements.
	This approach is O(n log n).
*/
SpanResult	Span::shortestSpan() {
	SpanResult		res;
	unsigned int	diff;

	if (this->n < 2)
		throw SpanInvalidException();

	// Shortest difference always occurs between adjacent elements
	std::sort(numbers.begin(), numbers.end());

	// Compare adjacent elements
	res.span = std::abs(numbers[1] - numbers[0]);
	res.begin = numbers[0];
	res.end = numbers[1];

	for (size_t i = 1; i < numbers.size() - 1; i++) {
		diff = numbers[i + 1] - numbers[i];
		if (diff < res.span) {
			res.span = diff;
			res.begin = numbers[i];
			res.end = numbers[i + 1];
		}
	}
	return (res);
}

/*
	Comparing each combination with i and j results in O(n²).
	First find the min and max items, then subtract them.
	This approach is O(n).
*/
SpanResult	Span::longestSpan() {
	SpanResult	res;

	if (this->n < 2)
		throw SpanInvalidException();

	// Find both the min and max elements in a single traversal.
	auto [minIt, maxIt] = std::minmax_element(numbers.begin(), numbers.end());

	res.begin = *minIt;
	res.end = *maxIt;
	res.span = static_cast<unsigned long>(*maxIt) - static_cast<unsigned long>(*minIt);

	return (res);
}

void	Span::fillWithRange(int start, int end) {
	for (int i = start; i <= end; i++)
		this->addNumber(i);
}

void	Span::write_span(SpanResult res, SpanType type) {
	if (type == SHORTEST)
		std::cout << "Shortest: \t";
	if (type == LONGEST)
		std::cout << "Longest: \t";

	std::cout
		<< C_BLUE
		<< "(begin: "
		<< res.begin
		<< " end: "
		<< res.end
		<< ")\t = "
		<< res.span
		<< RESET_COLOR
		<< std::endl;
}

void	Span::write_span_table(void) {
	unsigned int	diff;

	std::cout
			<< "Begin:\t\tEnd:\t\tDiff:"
			<< std::endl;
	for (size_t i = 1; i < numbers.size() - 1; i++) {
		diff = numbers[i + 1] - numbers[i];
		std::cout
			<< numbers[i + 1]
			<< "\t\t"
			<< numbers[i]
			<< "\t\t"
			<< C_BLUE
			<< diff
			<< RESET_COLOR
			<< std::endl;
	}
}

const char*	Span::SpanOutOfBoundsException::what() const throw() {
	return ("SpanOutOfBoundsException: Attempting to add values exceeding the capacity of created Span.");
}

const char*	Span::SpanInvalidException::what() const throw() {
	return ("SpanInvalidException: A span could not be calculated for these values.");
}
