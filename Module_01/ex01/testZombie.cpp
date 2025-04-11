/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testZombie.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:19:18 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/11 11:16:19 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <cassert>

void	assert_with_message(bool assertion, const std::string& message) {
	if (!assertion) {
        std::cerr << C_RED << "[ ❌ ] TEST FAILED " << RESET_COLOR << "for assertion: " << message << std::endl;
        assert(assertion);
    }
	std::cout << C_GREEN << "[ ✅ ] TEST PASSED " << RESET_COLOR << "for assertion: " << message << std::endl;
}
