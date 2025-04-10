/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 09:59:19 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/04/10 23:51:26 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

#define C_YELLOW "\033[1;33m"
#define C_RED "\x1B[1;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define RESET_COLOR "\033[0m"

class ClapTrap {
	private:
		static const int	DEFAULT_HEALTH = 10;
		static const int	DEFAULT_ENERGY = 10;
		static const int	DEFAULT_DAMAGE = 2;
		
		std::string			name;
		unsigned int		health;
		unsigned int		energy;
		unsigned int		damage;

	public:
		ClapTrap();
		ClapTrap(const std::string newName);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void    attack(const std::string& target);
		void    takeDamage(unsigned int amount);
		void    beRepaired(unsigned int amount);

		std::string		getName(void);
		void			setName(std::string newName);
		
		int				getHealth(void);
		void			setHealth(int newHealth);

		int				getEnergy(void);
		void			setEnergy(int newEnergy);

		int				getDamage(void);
		void			setDamage(int newDamage);

		std::string		toString(int value);
};

#endif
