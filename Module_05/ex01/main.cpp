/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:53:58 by quentin           #+#    #+#             */
/*   Updated: 2025/07/23 09:08:00 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"
#include "include/helpers.hpp"

int main(void) {

	// 1. Can sign
	{
		write_line();
		write_divider();
		write_title("TEST 1: Bureaucrat Successful Sign");

		Bureaucrat	bart = Bureaucrat("Bart", 10);
		Form		form = Form("Act 1", 20, 20, 20);

		write_line();
		bart.signForm(form);
		write_line();
	}
	write_divider();


	// 2. Sign failed
	{
		write_title("TEST 2: Bureaucrat Failed Sign");

		Bureaucrat	bart = Bureaucrat("Bart", 100);
		Form		form = Form("Act 1", 20, 20, 20);

		write_line();
		bart.signForm(form);
		write_line();
	}
	write_divider();


	// 3. BeSigned limits
	{
		write_title("TEST 3: Form beSigned() Limits");

		Bureaucrat	bart = Bureaucrat("Bart", 20);
		Bureaucrat	bob = Bureaucrat("Bob", 10);
		Bureaucrat	borris = Bureaucrat("Borris", 30);
		Form	form = Form("Act 1", 20, 20, 20);

		// Bart may sign
		write_line();
		try {
			form.beSigned(bart);
			std::cout
				<< C_BLUE
				<< bart.getName()
				<< " successfully signed "
				<< form.getName() << "."
				<< RESET_COLOR
				<< std::endl;
		} catch (const std::exception& e) {
			std::cout
				<< C_RED
				<< bart.getName()
				<< " could not sign "
				<< form.getName()
				<< " because: \n"
				<< e.what()
				<< RESET_COLOR
				<< std::endl;
		}

		// Bob may sign
		try {
			form.beSigned(bob);
			std::cout
				<< C_BLUE
				<< bob.getName()
				<< " successfully signed "
				<< form.getName() << "."
				<< RESET_COLOR
				<< std::endl;
		} catch (const std::exception& e) {
			std::cout
				<< C_RED
				<< bob.getName()
				<< " could not sign "
				<< form.getName()
				<< " because: \n"
				<< e.what()
				<< RESET_COLOR
				<< std::endl;
		}

		// Borris may not sign
		try {
			form.beSigned(borris);
			std::cout
				<< C_BLUE
				<< borris.getName()
				<< " successfully signed "
				<< form.getName() << "."
				<< RESET_COLOR
				<< std::endl;
		} catch (const std::exception& e) {
			std::cout
				<< C_RED
				<< borris.getName()
				<< " could not sign "
				<< form.getName()
				<< " because: \n"
				<< e.what()
				<< RESET_COLOR
				<< std::endl;
		}
		write_line();
	}
	write_divider();


	// 4. << Overload
	{
		write_title("TEST 4: Use << operator");
		Form application = Form();
		write_line();
		
		std::cout
			<< C_BLUE
			<< application
			<< RESET_COLOR
			<< std::endl;
		write_line();
	}
	write_divider();
}
