/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:54:06 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/04/04 15:25:45 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <sstream>

#include "../contact/Contact.hpp"
#include "../../includes/messages.hpp"

#define C_YELLOW "\033[1;33m"
#define C_RED "\x1B[1;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define RESET_COLOR "\033[0m"

#define ADD 	"ADD"
#define SEARCH	"SEARCH"
#define EXIT	"EXIT"

enum ContactFields {
	INDEX,
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	SECRET
};

class PhoneBook {
	private:
		Contact contacts[8];
		int		currentIndex;
		int		contactCount;

        int get_contactIndex() { return currentIndex % 8; }

	public:
		PhoneBook();
		~PhoneBook();

		bool			add_contact_field(Contact& contact, ContactFields field, std::string value);
		void			add();
		void			search();

		void			write_greering(void);
		void			write_contact(Contact contact);
		void			write_contacts(void);
		void			write_contact_detail(Contact contact);
		std::string		truncate(const std::string& str, size_t width);
		bool			is_all_digi(const std::string& str);
};

#endif
