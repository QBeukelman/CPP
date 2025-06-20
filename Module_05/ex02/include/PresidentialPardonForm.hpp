/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/19 15:20:30 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/19 15:26:01 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
	PresidentialPardonForm: Required grades: sign 25, exec 5
	Informs that <target> has been pardoned by Zaphod Beeblebrox.
*/

#ifndef PRESIDENTIALPARDENFORM_HPP
#define PRESIDENTIALPARDENFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

#define SIGN_PARDON_FORM 25
#define EXC_PARDON_FORM 5

class AForm;

class PresidentialPardonForm : public AForm {
	private:
		std::string		target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &newTarget);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		std::string		getTarget() const;
		void			execute(Bureaucrat const &executor) const;
};

#endif
