/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:46:23 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/03/14 17:10:24 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "../weapon/Weapon.hpp"

class HumanA {
	private:
		std::string		name;
		Weapon&			weapon; // Reference eusures weapon is mandatory

	public:
		HumanA();
		HumanA(std::string name, Weapon weapon);
		~HumanA();

		// Name
		void			setName(std::string newName);
		std::string		getName() const;

		// Weapon
		Weapon&			getWeapon() const;
		void			setWeapon(Weapon& newWeapon);
		
		// Attack
		void			attack() const;		
};

#endif
