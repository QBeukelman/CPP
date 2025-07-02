/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/01 10:23:28 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/02 13:29:51 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

enum SpanType {
	SHORTEST,
	LONGEST
};

struct SpanResult {
	unsigned int	span;
	int				begin;
	int				end;
};

class Span {
	private:
		unsigned int			n; // Max count for numbers
		std::vector<int>		numbers;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void		addNumber(int number);
		SpanResult	shortestSpan();
		SpanResult	longestSpan();
		void		write_span(SpanResult span, SpanType type);

		class SpanOutOfBoundsException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class SpanInvalidException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
