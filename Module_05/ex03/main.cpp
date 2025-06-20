/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/19 21:24:16 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/20 08:50:35 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/helpers.hpp"
#include "include/Intern.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/ShrubberyCreationForm.hpp"

int		main(void) {
	
	write_divider();
	write_title("TEST 1: Correct and Incorrect Form Creation");
	{
		Intern intern = Intern();
		
		try {
			// Correct
			intern.makeForm("presidential pardon", "Amsterdam");
			intern.makeForm("robotomy request", "Utrecht");
			intern.makeForm("shrubbery creation", "Den Haag");
			
			// Incorrect
			intern.makeForm("other form", "Rotterdam");
		} catch (std::exception& e) {
			std::cout
				<< C_RED
				<< "Could not create form because: \n"
				<< e.what()
				<< RESET_COLOR
				<< std::endl;
		}
	}
	write_divider();
}
