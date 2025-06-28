/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/28 14:40:56 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/28 15:12:12 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T> class Array {
	private:
		T*				data;
		unsigned int	size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array operator=(const Array& other);
		~Array();

		unsigned int	size(void) const;

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
