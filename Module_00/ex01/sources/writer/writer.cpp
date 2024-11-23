
#include "../../includes/include.hpp"


void	write_greeting() {
	std::cout << INTRO_MESSAGE << "\n\n";
	std::cout << TABLE_SCHEMA << "\n\n";
	std::cout << C_BLUE "add" RESET_COLOR << ADD_MANUAL << "\n";
	std::cout << C_BLUE "search" RESET_COLOR << SEARCH_MANUAL << "\n";
	std::cout << C_BLUE "exit" RESET_COLOR << EXIT_MANUAL << "\n\n";
}
