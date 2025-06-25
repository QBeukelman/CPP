/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/25 18:25:25 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/25 20:56:06 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
	return new A;

	`if(dynamic_cast<A *>(p))`


*/

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include "../include/helpers.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {};

Base*	Base::generate(void) {
	std::srand(std::time(0));
	
	int	random = rand() % 3;
	if (random == 0) {
		return (new A());
	} else if (random == 1) {
		return (new B());
	} else if (random == 2) {
		return (new C());
	}
	return (nullptr);
}

void	Base::identify(Base* p) {
	
	if (dynamic_cast<A *>(p)) {
		std::cout
			<< C_BLUE
			<< "Identified *A"
			<< RESET_COLOR
			<< std::endl;
	} else if (dynamic_cast<B *>(p)) {
		std::cout
			<< C_BLUE
			<< "Identified *B"
			<< RESET_COLOR
			<< std::endl;
	} else if (dynamic_cast<C *>(p)) {
		std::cout
			<< C_BLUE
			<< "Identified *C"
			<< RESET_COLOR
			<< std::endl;
	} else {
		std::cout
			<< C_RED
			<< "Could not cast this type."
			<< RESET_COLOR
			<< std::endl;
	}
}

void	Base::identify(Base& p) {
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout
			<< C_BLUE
			<< "Identified &A"
			<< RESET_COLOR
			<< std::endl;
		return ;
	} catch (...) {}
	
	try {
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout
			<< C_BLUE
			<< "Identified &B"
			<< RESET_COLOR
			<< std::endl;
		return ;
	} catch (...) {}
	
	try {
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout
			<< C_BLUE
			<< "Identified &C"
			<< RESET_COLOR
			<< std::endl;
		return ;
	} catch (std::bad_cast& e) {
		std::cout
			<< C_RED
			<< "Could not cast this type, with exception: "
			<< e.what() << '.'
			<< RESET_COLOR
			<< std::endl;
	}
}
