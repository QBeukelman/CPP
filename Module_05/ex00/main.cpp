/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:57:31 by quentin           #+#    #+#             */
/*   Updated: 2025/07/23 10:31:09 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/helpers.hpp"

int main(void) {

	// 1. Throw error with invalid constructor
	{
		write_divider();
		write_title("TEST 1: Invalid Paramatised Constructor");

		try {
			Bureaucrat jonny = Bureaucrat("Jonny", -1);
			std::cout
				<< C_BLUE
				<< jonny.getName()
				<< RESET_COLOR
				<< std::endl;
		} catch (std::exception& e) {
			std::cout
				<< C_RED
				<< e.what()
				<< RESET_COLOR;
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

		std::cout
			<< C_BLUE
			<< "Current grade for "
			<< maxBureaucrat.getName()
			<< " is "
			<< maxBureaucrat.getGrade() << "."
			<< RESET_COLOR
			<< std::endl;

		try {
			maxBureaucrat.incrementGrade();
			std::cout
				<< C_BLUE
				<< "Successfully incremented grade for "
				<< maxBureaucrat.getName() << "\n"
				<< "Grade currently: "
				<< maxBureaucrat.getGrade() << "."
				<< RESET_COLOR
				<< std::endl;
		} catch (std::exception& e) {
			std::cout
				<< C_RED
				<< "Attempted to increment grade for "
				<< maxBureaucrat.getName()
				<< " but an exception was caught: \n"
				<< e.what() << "." << "\n"
				<< "Grade currently: "
				<< maxBureaucrat.getGrade() << "."
				<< RESET_COLOR
				<< std::endl;
		}
		write_line();

		std::cout
			<< C_BLUE
			<< "Current grade for "
			<< minBureaucrat.getName()
			<< " is "
			<< minBureaucrat.getGrade() << "."
			<< RESET_COLOR
			<< std::endl;

		try {
			minBureaucrat.decrementGrade();
			std::cout
				<< C_BLUE
				<< "Successfully decremented grade for "
				<< minBureaucrat.getName() << "\n"
				<< "Grade currently: "
				<< minBureaucrat.getGrade() << "."
				<< RESET_COLOR
				<< std::endl;
		} catch (std::exception& e) {
			std::cout
				<< C_RED
				<< "Attempted to decrement grade for "
				<< minBureaucrat.getName()
				<< " but an exception was caught: \n"
				<< e.what() << "." << "\n"
				<< "Grade currently: "
				<< minBureaucrat.getGrade() << "."
				<< RESET_COLOR
				<< std::endl;
		}
		write_line();
	}
	write_divider();

	// 3. Successful increment & decrement
	{
		write_title("TEST 3: Successful Increment & Decrement");
		Bureaucrat bureaucratHightScore = Bureaucrat("bureaucrat_high_score", 3);
		Bureaucrat bureaucratLowScore = Bureaucrat("bureaucrat_low_score", 142);
		write_line();

		std::cout
			<< C_BLUE
			<< "Current grade for "
			<< bureaucratHightScore.getName()
			<< " is "
			<< bureaucratHightScore.getGrade() << "."
			<< RESET_COLOR
			<< std::endl;

		try {
			bureaucratHightScore.incrementGrade();
			std::cout
				<< C_BLUE
				<< "Successfully incremented grade for "
				<< bureaucratHightScore.getName() << "\n"
				<< "Grade currently: "
				<< bureaucratHightScore.getGrade() << "."
				<< RESET_COLOR
				<< std::endl;
		} catch (std::exception& e) {
			std::cout
				<< C_RED
				<< "Attempted to increment grade for "
				<< bureaucratHightScore.getName()
				<< " but an exception was caught: \n"
				<< e.what() << "." << "\n"
				<< "Grade currently: "
				<< bureaucratHightScore.getGrade() << "."
				<< RESET_COLOR
				<< std::endl;
		}
		write_line();

		std::cout
			<< C_BLUE
			<< "Current grade for "
			<< bureaucratLowScore.getName()
			<< " is "
			<< bureaucratLowScore.getGrade() << "."
			<< RESET_COLOR
			<< std::endl;

		try {
			bureaucratLowScore.decrementGrade();
			std::cout
				<< C_BLUE
				<< "Successfully decremented grade for "
				<< bureaucratLowScore.getName() << "\n"
				<< "Grade currently: "
				<< bureaucratLowScore.getGrade() << "."
				<< RESET_COLOR
				<< std::endl;
		} catch (std::exception& e) {
			std::cout
				<< C_RED
				<< "Attempted to decrement grade for "
				<< bureaucratLowScore.getName()
				<< " but an exception was caught: \n"
				<< e.what() << "." << "\n"
				<< "Grade currently: "
				<< bureaucratLowScore.getGrade() << "."
				<< RESET_COLOR
				<< std::endl;
		}
		write_line();
	}
	write_divider();

	// 4. Overlad operator
	{
		write_title("TEST 4: Use << operator");
		Bureaucrat jonny = Bureaucrat("Jonny", 120);
		write_line();

		std::cout
			<< C_BLUE
			<< jonny
			<< RESET_COLOR
			<< std::endl;
		write_line();
	}
	write_divider();
}
