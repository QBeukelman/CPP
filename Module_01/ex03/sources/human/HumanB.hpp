/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:10:53 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/03/14 17:45:09 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "../weapon/Weapon.hpp"

class HumanB {
	private:
		std::string		name;
		Weapon*			weapon; // Pointer allows weapon to be optional

	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();

		// Name
		void			setName(std::string newName);
		std::string		getName() const;

		// Weapon
		Weapon*			getWeapon() const;
		void			setWeapon(Weapon& newWeapon);
		
		// Attack
		void			attack() const;		
};

#endif
