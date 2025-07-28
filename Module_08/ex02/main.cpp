/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:13:19 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/07/28 11:30:59 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources/MutatedStack.tpp"
#include "include/writer.hpp"

#include <iostream>
#include <random>

int	main(void) {

	write_divider();
	write_title("TEST 1: Test Default Stack");
	{
		MutatedStack<int>	mstack;
		
		mstack.push(5);
		mstack.push(17);

		std::cout
			<< "Stack top: "
			<< C_BLUE
			<< mstack.top()
			<< RESET_COLOR
			<< ". And size: "
			<< C_BLUE
			<< mstack.size()
			<< RESET_COLOR
			<< std::endl;

		mstack.pop();

		std::cout
			<< "One item poped from stack, stack size: "
			<< C_BLUE
			<< mstack.size()
			<< RESET_COLOR
			<< std::endl;
	}

	write_divider();
	write_title("TEST 2: Iterate Mutated Stack");
	{
		// Random device
		std::random_device				rd;
		std::mt19937					gen(rd());
		std::uniform_int_distribution<>	dist(-1000, 1000);
		
		// Mutated Stack
		MutatedStack<int>				mstack;
		for (int i = 0; i < 20; i++) {
			mstack.push(dist(gen));
		}
		
		MutatedStack<int>::iterator		it = mstack.begin();
		MutatedStack<int>::iterator		ite = mstack.end();
		
		while (it != ite) {
			std::cout
				<< C_BLUE
				<< *it
				<< RESET_COLOR
				<< std::endl;
			++it;
		}
		std::stack<int>	s(mstack);
	}
	write_divider();
}

