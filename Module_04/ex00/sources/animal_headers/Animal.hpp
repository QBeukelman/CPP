/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:07:41 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/04/12 16:58:05 by qbeukelm         ###   ########.fr       */
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

class Animal {
	protected:
		std::string		type;

	public:
		Animal();
		Animal(const Animal &other);
		Animal& operator=(const Animal &other);
		~Animal();
		
		std::string		getType() const;
		void			setType(const std::string newType);
		virtual void	makeSound() const; 		// Virtual so that derived class `makeSound()` can be called.
};

#endif
