/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:22:03 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/04 15:58:58 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : currentIndex(0), contactCount(0) {}
PhoneBook::~PhoneBook() {}

bool	PhoneBook::add_contact_field(Contact& contact, ContactFields field, std::string value) {
	if (value.empty())
	{
		std::cout << C_RED << EMPTY_INPUT << RESET_COLOR << std::endl << std::endl;
		return (false);
	}
		
	switch (field) {
		case FIRST_NAME:
			contact.set_firstName(value);
			break ;
		case LAST_NAME:
			contact.set_lastName(value);
			break ;
		case NICKNAME:
			contact.set_nickname(value);
			break ;
		case PHONE_NUMBER: {
			if (!is_all_digi(value)) {
				std::cout << C_RED << INVALID_NUMBER << RESET_COLOR << std::endl << std::endl;
				return (false);
			}	
			contact.set_phoneNumber(value);
			break ;
		}
		case SECRET:
			contact.set_darkestSecret(value);
			break ;
		case INDEX: default:
			break ;
	}
	return (true);
}

void	PhoneBook::add() {
	int				index;
	std::string		input;
	Contact			contact;

	while (1) {
		std::cout << C_BLUE << "add\t" << RESET_COLOR << "first name:\t";
		getline(std::cin, input);
		if (add_contact_field(contact, FIRST_NAME, input) == false)
			return ;

		std::cout << C_BLUE << "add\t" << RESET_COLOR << "last name:\t";
		getline(std::cin, input);
		if (add_contact_field(contact, LAST_NAME, input) == false)
			return ;

		std::cout << C_BLUE << "add\t" << RESET_COLOR << "nickname:\t";
		getline(std::cin, input);
		if (add_contact_field(contact, NICKNAME, input) == false)
			return ;

		std::cout << C_BLUE << "add\t" << RESET_COLOR << "phone number:\t";
		getline(std::cin, input);
		if (add_contact_field(contact, PHONE_NUMBER, input) == false) {
			return ;
		}

		std::cout << C_BLUE << "add\t" << RESET_COLOR << "darkest secret:\t";
		getline(std::cin, input);
		if (add_contact_field(contact, SECRET, input) == false)
			return ;

		break ;
	}

	index = get_contactIndex();
	contact.set_index(index);
	contacts[index] = contact;
	currentIndex++;
	if (contactCount < 8)
		contactCount++;

	std::cout << C_GREEN << ADDED_CONTACT << RESET_COLOR << "\n\n";
}

void	PhoneBook::search() {
	std::string		input;
	int				index = 0;

	if (this->contacts[0].get_firstName().empty()) {
		std::cout << EMPTY_BOOK << "\n\n";
		return ;
	
	}
	
	write_contacts();

	std::cout << C_BLUE << "search\t" << RESET_COLOR << SEARCH_PROMPT << this->contactCount << ":\t";
	getline(std::cin, input);
	if (input.empty())
	{
		std::cout << C_RED << EMPTY_INPUT << RESET_COLOR << std::endl << std::endl;
		return ;
	}
	if (input.length() > 1)
	{
		std::cout << C_RED << INVALID_INDEX << "\n\n";
		return ;
	}
	if (std::isdigit(input[0]))
		index = input[0] - '0' - 1;

	if (index >= 0 && index <= 7 && !this->contacts[index].get_firstName().empty()) {
		write_contact_detail(this->contacts[index]);
	} else {
		std::cout << C_RED << INVALID_INDEX << RESET_COLOR << "\n\n";
	}
}

void	PhoneBook::write_greering(void) {
	std::cout << INTRO_MESSAGE << "\n\n";
	std::cout << TABLE_SCHEMA << "\n\n";
	std::cout << C_BLUE "ADD" RESET_COLOR << ADD_MANUAL << "\n";
	std::cout << C_BLUE "SEARCH" RESET_COLOR << SEARCH_MANUAL << "\n";
	std::cout << C_BLUE "EXIT" RESET_COLOR << EXIT_MANUAL << "\n\n";
}


void	PhoneBook::write_contact(Contact contact) {
	std::cout << C_GREEN << "[" << contact.get_index() + 1 << "]";
	std::cout << TABLE_SEPERATOR << std::setw(MAX_FIELD_WIDTH) << truncate(contact.get_firstName(), MAX_FIELD_WIDTH);
	std::cout << TABLE_SEPERATOR << std::setw(MAX_FIELD_WIDTH) << truncate(contact.get_lastName(), MAX_FIELD_WIDTH);
	std::cout << TABLE_SEPERATOR << std::setw(MAX_FIELD_WIDTH) << truncate(contact.get_nickname(), MAX_FIELD_WIDTH);
	std::cout << RESET_COLOR << "\n";
}

void	PhoneBook::write_contacts(void) {
	int		index;

	index = get_contactIndex();
	for (int i = 0; i < this->contactCount; i++) {
		write_contact(this->contacts[i]);
	}
	std::cout << std::endl;
}

void	PhoneBook::write_contact_detail(Contact contact) {
	std::cout
		<< "First Name: \t" << C_GREEN << contact.get_firstName() << RESET_COLOR << std::endl
		<< "Last Name: \t" << C_GREEN << contact.get_lastName() << RESET_COLOR << std::endl
		<< "Nickname: \t" << C_GREEN << contact.get_nickname() << RESET_COLOR << std::endl
		<< "Phone Number: \t" << C_GREEN << contact.get_phoneNumber() << RESET_COLOR << std::endl
		<< "Secret: \t" << C_GREEN << contact.get_darketSecret() << RESET_COLOR << std::endl << std::endl;
}

std::string		PhoneBook::truncate(const std::string& str, size_t width) {
	if (str.length() > width) {
		return (str.substr(0, width - 1) + ".");
	}
	return (str);
}

bool	PhoneBook::is_all_digi(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(static_cast<unsigned char>(str[i]))) {
			return (false);
		}
	}
	return (!str.empty());
}
