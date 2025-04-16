/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/16 16:27:08 by quentin       #+#    #+#                 */
/*   Updated: 2025/04/16 16:27:25 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define	IDEAS_MAX 100

class Brain {
	private:
		std::string		ideas[IDEAS_MAX];

	public:
		Brain();
		Brain(const Brain &other);
		Brain& operator=(const Brain &other);
		~Brain();

		void			setIdea(int index, std::string idea);
		std::string		getIdea(int	index);
};

#endif
