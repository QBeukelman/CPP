/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/16 16:22:21 by quentin       #+#    #+#                 */
/*   Updated: 2025/04/16 16:39:54 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#define C_YELLOW "\033[1;33m"
#define C_RED "\x1B[1;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define RESET_COLOR "\033[0m"

#include <string>
#include "Brain.hpp"

class AAnimal {
	protected:
		std::string	type;

	public:
		AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();

		std::string		getType() const;
		void			setType(const std::string newType);

		virtual void	makeSound() const;
		virtual Brain	&getBrain() const = 0;		// Pure virtual
};

#endif
