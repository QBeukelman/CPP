/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/10 22:19:52 by quentin       #+#    #+#                 */
/*   Updated: 2025/04/10 23:49:55 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

#define C_YELLOW "\033[1;33m"
#define C_RED "\x1B[1;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define RESET_COLOR "\033[0m"

class ScavTrap: public ClapTrap {
	private:
		static const int	SCAV_DEFAULT_HEALTH = 100;
		static const int	SCAV_DEFAULT_ENERGY = 50;
		static const int	SCAV_DEFAULT_DAMAGE = 20;

    public:
		ScavTrap();
		ScavTrap(std::string newName);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap &other);
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
};

#endif
