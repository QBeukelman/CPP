/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:18:31 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:18:35 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include "../../../utils/utils.hpp"

class Weapon {
	private:
		std::string		type;

	public:
		Weapon();
		Weapon(const std::string& type);
		~Weapon();

		void				setType(const std::string& newType);
		const std::string&	getType() const;
};

#endif
