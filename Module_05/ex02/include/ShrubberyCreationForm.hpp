/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/16 07:48:10 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/19 14:07:53 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
	ShrubberyCreationForm: Required grades: sign 145, exec 137
	Creates a file <target>_shrubbery in the working directory and writes ASCII trees
	inside it.
*/

#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

#define SIGN_SHRUBBERY_FORM 145
#define EXC_SHRUBBERY_FORM 137

class AForm;

class ShrubberyCreationForm : public AForm {
	private:
		std::string		target;
		
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &newTarget);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		std::string		getTarget() const;
		void			execute(Bureaucrat const &executor) const;
};

#define ASCII_TREE "\n\
 _                  \n\
| |                 \n\
| |_ _ __ ___  ___  \n\
| __| '__/ _ \\/ _ \\ \n\
| |_| | |  __/  __/ \n\
 \\__|_|  \\___|\\___| \n\
\n\
"

#endif
