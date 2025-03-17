/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:22:09 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:22:20 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.hpp"

void	write_greeting() {
	std::cout << INTRO_MESSAGE << "\n\n";
	std::cout << TABLE_SCHEMA << "\n\n";
	std::cout << C_BLUE "add" RESET_COLOR << ADD_MANUAL << "\n";
	std::cout << C_BLUE "search" RESET_COLOR << SEARCH_MANUAL << "\n";
	std::cout << C_BLUE "exit" RESET_COLOR << EXIT_MANUAL << "\n\n";
}

static std::string	truncate(std::string str, int width) {
	int		fill_len;

	if (str.length() > width) {
		return (str.substr(0, width) + ".");
	} else {
		fill_len = width - str.length();
		while (fill_len > 0) {
			str.append(" ");
			fill_len--;
		}
		return (str);
	}
	return str;
}

void	write_contact(Contact contact) {
	std::cout << C_GREEN << "[" << contact.get_index() << "]";
	std::cout << TABLE_SEPERATOR << truncate(contact.get_firstName(), MAX_FIELD_WIDTH);
	std::cout << TABLE_SEPERATOR << truncate(contact.get_lastName(), MAX_FIELD_WIDTH);
	std::cout << TABLE_SEPERATOR << truncate(contact.get_phoneNumber(), MAX_FIELD_WIDTH);
	std::cout << RESET_COLOR << "\n\n";
}
