/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/01 10:41:40 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/02 13:31:56 by quentinbeuk   ########   odam.nl         */
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
	SpanResult	res;
	int			shortest;

	if (this->n < 2)
		throw SpanInvalidException();

	// Shortest difference always occurs between adjacent elements
	std::sort(numbers.begin(), numbers.end());

	// Compare adjacent elements
	shortest = std::abs(numbers[1] - numbers[0]);
	res.begin = numbers[0];
	res.end = numbers[1];

	for (size_t i = 1; i < numbers.size() - 1; i++) {
		int	diff = std::abs(numbers[i + 1] - numbers[i]);
		if (diff < shortest) {
			shortest = diff;
			res.begin = numbers[i];
			res.begin = numbers[i + 1];
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
	res.span = res.end - res.begin;

	return (res);
}

void Span::write_span(SpanResult res, SpanType type) {
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
		<< ") = "
		<< res.span
		<< RESET_COLOR
		<< std::endl;
}

const char*	Span::SpanOutOfBoundsException::what() const throw() {
	return ("SpanOutOfBoundsException");
}

const char*	Span::SpanInvalidException::what() const throw() {
	return ("SpanInvalidException");
}
