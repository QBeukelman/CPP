/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:23:28 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/07/28 11:22:00 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

enum SpanType {
	SHORTEST,
	LONGEST
};

struct SpanResult {
	unsigned long		span;
	int					begin;
	int					end;
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
		void		fillWithRange(int start, int end);
		void		write_span(SpanResult span, SpanType type);
		void		write_span_table(void);
		
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
