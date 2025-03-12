
#include "Zombie.hpp"

void	assert_with_message(bool assertion, const std::string& message) {
	if (!assertion) {
        std::cerr << C_RED << "[ ❌ ] TEST FAILED " << RESET_COLOR << "for assertion: " << message << std::endl;
        assert(assertion);
    }
	std::cout << C_GREEN << "[ ✅ ] TEST PASSED " << RESET_COLOR << "for assertion: " << message << std::endl;
}
