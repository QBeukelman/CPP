
#include "magaphone.hpp"

Megaphone::Megaphone() : message("") {}

std::string Megaphone::str_upper(const std::string str) {
	std::string result;
	result.reserve(str.size());

	for (size_t i = 0; i < str.size(); i++) {
		result += std::toupper(str[i]);
	}
	return (result);
}

std::string join_args(int argc, char **argv) {
	std::string str;
	str.reserve(2048);

	for (int i = 1; i < argc; i++) {
		str.append(argv[i]);
	}
	return (str);
}

int main(int argc, char **argv) {
	Megaphone	megaphone;

	megaphone.message = megaphone.str_upper(join_args(argc, argv));
	std::cout << megaphone.message << "\n";
};
