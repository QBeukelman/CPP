/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/12 13:07:41 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/04/16 15:42:31 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define C_YELLOW "\033[1;33m"
#define C_RED "\x1B[1;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define RESET_COLOR "\033[0m"

#include <string>
#include "Brain.hpp"

class Animal {
	protected:
		std::string		type;

	public:
		Animal();
		Animal(const Animal &other);
		Animal& operator=(const Animal &other);
		virtual ~Animal();
		
		std::string		getType() const;
		void			setType(const std::string newType);
		
		virtual void	makeSound() const;
		virtual Brain	&getBrain() const = 0;
};

#endif
