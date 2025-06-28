/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/28 12:12:17 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/28 12:12:26 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/writer.hpp"

void write_line() {
	std::cout << std::endl;
}

void write_divider() {
	std::cout << std::endl << "---------------------\n\n";
}

void write_title(const std::string& title) {
	std::cout << C_YELLOW << title << RESET_COLOR << "\n\n";
}
