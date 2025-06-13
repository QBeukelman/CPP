/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentin <quentin@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/13 10:57:31 by quentin       #+#    #+#                 */
/*   Updated: 2025/06/13 13:21:00 by quentin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"

void		write_line(void) { std::cout << std::endl; }
void		write_divider(void) { std::cout << std::endl << "---------------------\n\n"; }
void		write_title(std::string title) { std::cout << C_BLUE << title << RESET_COLOR << "\n\n"; };

int main(void) {

	// 1. Throw error with invalid constructor
	{
		write_divider();
		write_title("TEST 1: Invalid Paramatised Constructor");

		try {
			Bureaucrat newBur = Bureaucrat("Jonny", -1);
			std::cout << newBur.getName();
		} catch (std::exception& e) {
			std::cout << e.what();
		}

		write_line();
		write_divider();
	}


	// 2. Out of rande
	{
		write_title("TEST 2: Out of Range");
		Bureaucrat maxBureaucrat = Bureaucrat("max_bureaucrat", MAX_GRADE);
		Bureaucrat minBureaucrat = Bureaucrat("min_bureaucrat", MIN_GRADE);
		write_line();

		try {
			std::cout
				<< "Current grade for "
				<< maxBureaucrat.getName()
				<< " is "
				<< maxBureaucrat.getGrade()
				<< "." << std::endl;
			maxBureaucrat.incrementGrade();
			std::cout
				<< "Successfully incremented grade for "
				<< maxBureaucrat.getName() << "\n"
				<< "Grade currently: "
				<< maxBureaucrat.getGrade() << "."
				<< std::endl;
		} catch (std::exception& e) {
			std::cout
				<< "Attempted to increment grade for "
				<< maxBureaucrat.getName()
				<< " but an exception was caught: \n"
				<< e.what() << "." << "\n"
				<< "Grade currently: "
				<< maxBureaucrat.getGrade() << "."
				<< std::endl;
		}
		write_line();

		try {
			std::cout
				<< "Current grade for "
				<< minBureaucrat.getName()
				<< " is "
				<< minBureaucrat.getGrade()
				<< "." << std::endl;
			minBureaucrat.decrementGrade();
			std::cout
				<< "Successfully decremented grade for "
				<< minBureaucrat.getName() << "\n"
				<< "Grade currently: "
				<< minBureaucrat.getGrade() << "."
				<< std::endl;
		} catch (std::exception& e) {
			std::cout
				<< "Attempted to decrement grade for "
				<< minBureaucrat.getName()
				<< " but an exception was caught: \n"
				<< e.what() << "." << "\n"
				<< "Grade currently: "
				<< minBureaucrat.getGrade() << "."
				<< std::endl;
		}
		write_line();
	}
	write_divider();

	// 3. Successful increment & decrement
	{
		write_title("TEST 3: Successful Incremetn & Decrement");
		Bureaucrat bureaucratHightScore = Bureaucrat("bureaucrat_high_score", 3);
		Bureaucrat bureaucratLowScore = Bureaucrat("bureaucrat_low_score", 142);
		write_line();

		try {
			std::cout
				<< "Current grade for "
				<< bureaucratHightScore.getName()
				<< " is "
				<< bureaucratHightScore.getGrade()
				<< "." << std::endl;
			bureaucratHightScore.incrementGrade();
			std::cout
				<< "Successfully incremented grade for "
				<< bureaucratHightScore.getName() << "\n"
				<< "Grade currently: "
				<< bureaucratHightScore.getGrade() << "."
				<< std::endl;
		} catch (std::exception& e) {
			std::cout
				<< "Attempted to increment grade for "
				<< bureaucratHightScore.getName()
				<< " but an exception was caught: \n"
				<< e.what() << "." << "\n"
				<< "Grade currently: "
				<< bureaucratHightScore.getGrade() << "."
				<< std::endl;
		}
		write_line();

		try {
			std::cout
				<< "Current grade for "
				<< bureaucratLowScore.getName()
				<< " is "
				<< bureaucratLowScore.getGrade()
				<< "." << std::endl;
			bureaucratLowScore.decrementGrade();
			std::cout
				<< "Successfully decremented grade for "
				<< bureaucratLowScore.getName() << "\n"
				<< "Grade currently: "
				<< bureaucratLowScore.getGrade() << "."
				<< std::endl;
		} catch (std::exception& e) {
			std::cout
				<< "Attempted to decrement grade for "
				<< bureaucratLowScore.getName()
				<< " but an exception was caught: \n"
				<< e.what() << "." << "\n"
				<< "Grade currently: "
				<< bureaucratLowScore.getGrade() << "."
				<< std::endl;
		}
		write_line();
	}
	write_divider();
}
