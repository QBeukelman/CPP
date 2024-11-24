
#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <iostream>
#include <string>
#include <cctype>

#include "messages.hpp"

#define C_YELLOW "\033[1;33m"
#define C_RED "\x1B[1;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define RESET_COLOR "\033[0m"

// Commands
#define ADD 	"add"
#define SEARCH	"search"
#define EXIT	"exit"

enum ContactFields {
	INDEX,
	FIRST_NAME,
	LAST_NAME,
	PHONE_NUMBER
};

class Contact {
	private:
		int				index;
		std::string		firstName;
		std::string		lastName;
		std::string		phoneNumber;

	public:
		Contact();
		~Contact();

		int				get_index();
		std::string		get_firstName();
		std::string		get_lastName();
		std::string		get_phoneNumber();

		void			set_index(int index);
		void			set_firstName(std::string firstName);
		void			set_lastName(std::string lastName);
		void			set_phoneNumber(std::string phoneNumber);
};

class PhoneBook {
	private:
		Contact contacts[8];
		int		currentIndex;

        int get_contactIndex() { return currentIndex % 8; }

	public:
		PhoneBook();
		~PhoneBook();

		void			add();
		void			search();
};

//===============================================================: writer
// writer.cpp
void	write_greeting();
void	write_contact(Contact contact);

#endif
