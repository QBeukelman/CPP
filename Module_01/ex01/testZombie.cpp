/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testZombie.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:19:18 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:19:21 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	assert_with_message(bool assertion, const std::string& message) {
	if (!assertion) {
        std::cerr << C_RED << "[ ❌ ] TEST FAILED " << RESET_COLOR << "for assertion: " << message << std::endl;
        assert(assertion);
    }
	std::cout << C_GREEN << "[ ✅ ] TEST PASSED " << RESET_COLOR << "for assertion: " << message << std::endl;
}
