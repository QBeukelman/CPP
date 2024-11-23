
#include "../includes/include.hpp"

int	program_loop() {
	std::string		command;

	while (1) {
		std::cout << ENTER_CMD << "\n";
		getline(std::cin, command);

		if (command == ADD) {

		} else if (command == SEARCH) {

		} else if (command == EXIT) {
			std::cout << C_RED "exit" RESET_COLOR << EXIT_PROGRAM << "\n\n";
			return (1);
		} else {
			std::cout << INVALID_CMD << "\n";
		}
	}
	return (1);
}

int main() {
	write_greeting();
	program_loop();
}
