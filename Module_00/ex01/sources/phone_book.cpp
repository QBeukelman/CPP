/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:57:43 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/04/04 15:05:06 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact/Contact.hpp"
#include "phone_book/PhoneBook.hpp"

int	program_loop(PhoneBook phoneBook) {
	std::string		command;

	while (1) {
		std::cout << C_YELLOW << ENTER_CMD << RESET_COLOR;
		getline(std::cin, command);

		if (command == ADD) {
			phoneBook.add();
		} else if (command == SEARCH) {
			phoneBook.search();
		} else if (command == EXIT) {
			std::cout << C_RED "exit" RESET_COLOR << EXIT_PROGRAM << "\n\n";
			return (1);
		} else {
			std::cout << C_RED << INVALID_CMD << RESET_COLOR << "\n\n";
		}
	}
	return (1);
}

int main() {
	PhoneBook phoneBook;

	phoneBook.write_greering();
	program_loop(phoneBook);
}
