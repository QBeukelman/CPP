/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:35:02 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/07/28 11:12:03 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources/easyfind.tpp"
#include "include/writer.hpp"

#include <list>
#include <array>
#include <vector>
#include <deque>

int main(void) {
	
	write_divider();
	write_title("TEST 1: Does Throw Correctly");
	{
		std::vector<int>	nums = {1, 2, 3, 4, 5};

		try {
			auto it = easyfind(nums, 999);
			std::cerr
				<< C_RED
				<< "FAILED: easyfind() found the given number: "
				<< *it
				<< ", and no exception was thrown."
				<< RESET_COLOR
				<< std::endl;
		} catch (std::exception &e) {
			std::cout
				<< C_BLUE
				<< "PASSED: easyfind() did not find given value and correctly threw: \n"
				<< C_RED
				<< e.what()
				<< RESET_COLOR
				<< std::endl;
		}
	}

	write_divider();
	write_title("TEST 2: Easyfind() with vector<int>");
	{
		std::vector<int>	vectorContainer;

		for (int i = 0; i < 10; i++) {
			vectorContainer.push_back(i);
		}
		std::cout
			<< "Found value in vector<int>: "
			<< C_BLUE
			<< *easyfind(vectorContainer, 9)
			<< RESET_COLOR
			<< std::endl;
	}

	write_divider();
	write_title("TEST 3: Easyfind() with list<int>");
	{
		std::list<int>	vectorContainer;

		for (int i = 0; i < 10; i++) {
			vectorContainer.push_back(i);
		}
		std::cout
			<< "Found value in list<int>: "
			<< C_BLUE
			<< *easyfind(vectorContainer, 9)
			<< RESET_COLOR
			<< std::endl;
	}

	write_divider();
	write_title("TEST 4: Easyfind() with deque<int>");
	{
		std::deque<int>	vectorContainer;

		for (int i = 0; i < 10; i++) {
			vectorContainer.push_back(i);
		}
		std::cout
			<< "Found value in deque<int>: "
			<< C_BLUE
			<< *easyfind(vectorContainer, 9)
			<< RESET_COLOR
			<< std::endl;
	}
	write_divider();
}
