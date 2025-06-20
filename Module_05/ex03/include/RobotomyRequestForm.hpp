/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/19 13:46:03 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/19 14:07:30 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
	RobotomyRequestForm: Required grades: sign 72, exec 45
	Makes some drilling noises, then informs that <target> has been robotomized
	successfully 50% of the time. Otherwise, it informs that the robotomy failed.
*/

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

#define SIGN_ROBOTOMY_FORM 72
#define EXC_ROBOTOMY_FORM 45

class AForm;

class RobotomyRequestForm : public AForm {
	private:
		std::string		target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &newTarget);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		std::string		getTarget() const;
		void			execute(Bureaucrat const &executor) const;
};

#endif
