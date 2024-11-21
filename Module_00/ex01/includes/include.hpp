
#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <iostream>
#include <string>
#include <cctype>

#include "messages.hpp"

#define ADD 	"add"
#define SEARCH	"search"
#define EXIT	"exit"

// enum Commands {
// 	ADD,
// 	SEARCH,
// 	EXIT,
// };

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

	public:
		PhoneBook();
		~PhoneBook();
};

//===============================================================: writer
// writer.cpp
void	write_greeting();

#endif
