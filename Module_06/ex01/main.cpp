/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/25 17:36:39 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/25 19:41:40 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/Serializer.hpp"
#include "include/helpers.hpp"

#include <iostream>
#include <iomanip>

int	main(void) {

	write_divider();
	write_title("TEST 1: Serialize and Deserialize");
	{
		Data data;
		
		data.c = 'a';
		data.str = "Hello Codam!";
		data.num = 42;
		data.f = 42.2f;
		
		uintptr_t raw = Serializer::serialize(&data);
		std::cout
			<< C_BLUE
			<< "Raw: \t"
			<< raw
			<< RESET_COLOR
			<< std::endl;
		
		Data* dataDeserialized = Serializer::deserialize(raw);
		if (dataDeserialized == &data) {
			std::cout
				<< C_BLUE
				<< "Char: \t"
				<< dataDeserialized->c << "\n"
				<< "Str: \t"
				<< dataDeserialized->str << "\n"
				<< "Int: \t"
				<< dataDeserialized->num << "\n"
				<< "Float: \t"
				<< std::fixed
				<< std::setprecision(1)
				<< dataDeserialized->f << "f"
				<< RESET_COLOR
				<< std::endl;
		} else {
			std::cout
				<< C_RED
				<< "Could not deserialize data."
				<< RESET_COLOR;
		}
	}
	write_divider();
}
