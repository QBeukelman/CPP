/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generator.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/10 16:27:14 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/10 16:41:25 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.hpp"

#include <iostream>
#include <random>

int		main(int argc, char **argv) {
	
	if (argc != 3) {
		std::cerr
			<< C_RED
			<< "INVALID ARGS ./generator `count` `rage`."
			<< RESET_COLOR
			<< std::endl;
		return (0);
	}

	int		count = std::stoi(argv[1]);
	int		range = std::stoi(argv[2]);
	
	std::random_device				rd;
	std::mt19937					gen(rd());
	std::uniform_int_distribution<>	dist(0, range);

	for (int i = 0; i < count; i++) {
		std::cout << dist(gen) << " ";
	}
	return (1);
}
