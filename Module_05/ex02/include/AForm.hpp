/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 07:52:39 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/07/18 11:06:08 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

#define C_RED "\x1B[1;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define RESET_COLOR "\033[0m"

#define DEFAULT_IS_SIGNED false
#define DEFAULT_FORM_NAME "Default form"
#define DEFAULT_TARGET "Default target"

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		const int			grade;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:
		AForm();
		AForm(std::string newName, int newGrade, int newGradeToSign, int newGradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		// Members
		std::string		getName() const;
		int				getGrade() const;
		bool			getSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		void			beSigned(const Bureaucrat& bureaucrat);
		bool			getIsSigned() const;

		virtual void	execute(Bureaucrat const &executor) const = 0;		// pure virtual

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

std::ostream&	operator<<(std::ostream &out, AForm const &form);

#endif
