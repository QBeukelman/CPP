/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:20:31 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:20:33 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <memory>
#include "../utils/utils.hpp"

class Zombie {
	private:
		std::string		name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void				announce(void);
		static Zombie*		newZombie(std::string name);
		static void			randomChump(std::string name);
};

#endif
