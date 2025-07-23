/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:24:16 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/07/23 09:21:21 by qbeukelm         ###   ########.fr       */
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
			AForm* pardonForm = intern.makeForm("presidential pardon", "Amsterdam");
			delete (pardonForm);
			
			AForm* robotomyForm = intern.makeForm("robotomy request", "Utrecht");
			delete (robotomyForm);
			
			AForm* shrubberyForm = intern.makeForm("shrubbery creation", "Den Haag");
			delete (shrubberyForm);
			
			// Incorrect
			AForm* otherForm = intern.makeForm("other form", "Rotterdam");
			delete (otherForm);

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
