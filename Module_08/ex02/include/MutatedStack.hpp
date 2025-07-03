/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutatedStack.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/03 11:08:23 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/03 13:34:03 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTATEDSTACK_HPP
#define MUTATEDSTACK_HPP

#include <stack>
#include <deque>

/*
	std::stack is a container adaptor, it adapts to another container, usually
	std::deque<T> which is not iterable. Stack has a protected member called `c`
	which exposes the underlying container.
*/

template<typename T>
class MutatedStack : public std::stack<T> {
	public:
		MutatedStack();
		MutatedStack(const MutatedStack& other);
		MutatedStack& operator=(const MutatedStack& other);
		~MutatedStack();
	
		using	std::stack<T>::c; // Gives access to protected member
		using	iterator = typename std::deque<T>::iterator;
		using	const_iterator = typename std::deque<T>::const_iterator;

		iterator		begin();
		iterator		end();

		const_iterator	begin() const;
		const_iterator	end() const;

		const_iterator	cbegin() const;
		const_iterator	cend() const;
};

#endif
