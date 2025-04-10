/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/11 00:16:31 by quentin       #+#    #+#                 */
/*   Updated: 2025/04/11 00:21:48 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP    
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    private:
        static const int	FRAG_DEFAULT_HEALTH = 100;
		static const int	FRAG_DEFAULT_ENERGY = 100;
		static const int	FRAG_DEFAULT_DAMAGE = 30;

    public:
        FragTrap();
        FragTrap(std::string newName);
        FragTrap(const FragTrap &other);
        FragTrap& operator=(const FragTrap &other);
        ~FragTrap();

        void    attack(const std::string &target);
        void    highFiveGuys(void);
};

#endif
