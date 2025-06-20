/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/18 20:11:58 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/19 21:20:35 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/helpers.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/ShrubberyCreationForm.hpp"

int		main(void) {

	write_divider();
	write_title("TEST 1: Shrubbery Creation Form");
	// sign: 145 - exc: 137
	{
		ShrubberyCreationForm form = ShrubberyCreationForm("Amsterdam");
		Bureaucrat tom = Bureaucrat("Tom", 140);

		tom.signForm(form);
		tom.executeForm(form);
	}
	write_divider();

	write_title("TEST 2: Robotomy Request Form");
	// sign: 72 - exc: 45
	{
		RobotomyRequestForm form = RobotomyRequestForm("Amsterdam");
		Bureaucrat tom = Bureaucrat("Tom", 30);

		tom.signForm(form);
		tom.executeForm(form);
	}
	write_divider();

	write_title("TEST 3: Presidential Pardon Form");
	// sign: 25 - exc: 5
	{
		PresidentialPardonForm form = PresidentialPardonForm("Amsterdam");
		Bureaucrat tom = Bureaucrat("Tom", 1);

		tom.signForm(form);
		tom.executeForm(form);
	}
	write_divider();
}
