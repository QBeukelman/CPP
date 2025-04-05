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

#define C_YELLOW "\033[1;33m"
#define C_RED "\x1B[1;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define RESET_COLOR "\033[0m"

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
