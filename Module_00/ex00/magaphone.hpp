
#ifndef MEGAPHONE_HPP
#define MEGAPHONE_HPP

#include <iostream>
#include <string>
#include <cctype>

class Megaphone {
	public:
		Megaphone();

		std::string message;

		std::string str_upper(const std::string str);
};

#endif
