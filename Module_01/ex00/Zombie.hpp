/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:20:31 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/11 11:11:55 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

#define C_YELLOW "\033[1;33m"
#define C_RED "\x1B[1;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define RESET_COLOR "\033[0m"

class Zombie {
	private:
		std::string		name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	announce(void);
		void	setName(std::string name);
};

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);

#endif
