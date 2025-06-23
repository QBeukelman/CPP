/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/13 13:32:16 by quentin       #+#    #+#                 */
/*   Updated: 2025/06/23 16:49:23 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>

#define DEFAULT_IS_SIGNED false
#define DEFAULT_FORM_NAME "default_form"

class Bureaucrat;

class Form {
	private:
		std::string	name;
		int			grade;
		bool		isSigned;
		int			gradeToSign;
		int			gradeToExecute;

	public:
		Form();
		Form(std::string newName, int newGrade, int newGradeToSign, int newGradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		// Members
		std::string	getName() const;
		int			getGrade() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(const Bureaucrat& bureaucrat);

		// Public exception inheriting from std exception
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &out, Form const &form);

#endif
