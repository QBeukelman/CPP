
#include "../includes/include.hpp"

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

	write_greeting();
	program_loop(phoneBook);
}
