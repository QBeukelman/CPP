/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/13 14:53:58 by quentin       #+#    #+#                 */
/*   Updated: 2025/06/13 15:19:38 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"

void		write_line(void) { std::cout << std::endl; }
void		write_divider(void) { std::cout << std::endl << "---------------------\n\n"; }
void		write_title(std::string title) { std::cout << C_BLUE << title << RESET_COLOR << "\n\n"; };

int main(void) {
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

	{
		write_title("TEST 2: Bureaucrat Failed Sign");

		Bureaucrat	bart = Bureaucrat("Bart", 100);
		Form		form = Form("Act 1", 20, 20, 20);

		write_line();
		bart.signForm(form);
		write_line();
	}
	write_divider();

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
				<< bart.getName()
				<< " successfully signed "
				<< form.getName() << "."
				<< std::endl;
		} catch (const std::exception& e) {
			std::cout
				<< bart.getName()
				<< " could not sign "
				<< e.what()
				<< " because: \n"
				<< std::endl;
		}

		// Bob may sign
		try {
			form.beSigned(bob);
			std::cout
				<< bob.getName()
				<< " successfully signed "
				<< form.getName() << "."
				<< std::endl;
		} catch (const std::exception& e) {
			std::cout
				<< bob.getName()
				<< " could not sign "
				<< e.what()
				<< " because: \n"
				<< std::endl;
		}

		// Borris may not sign
		try {
			form.beSigned(borris);
			std::cout
				<< borris.getName()
				<< " successfully signed "
				<< form.getName() << "."
				<< std::endl;
		} catch (const std::exception& e) {
			std::cout
				<< borris.getName()
				<< " could not sign "
				<< " because: \n"
				<< e.what()
				<< std::endl;
		}
		write_line();
	}
	write_divider();
}
