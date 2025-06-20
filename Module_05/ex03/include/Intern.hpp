/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/19 21:24:29 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/20 08:42:42 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm*	PresidentialPardon(const std::string &target);
		AForm*	RobotomyRequest(const std::string &target);
		AForm*	ShrubberyCreation(const std::string &target);
		AForm*	makeForm(const std::string& name, const std::string& target);

		class InternFormException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
