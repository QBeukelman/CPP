/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/25 20:30:01 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/25 20:59:55 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/Base.hpp"
#include "include/A.hpp"
#include "include/B.hpp"
#include "include/C.hpp"
#include "include/Z.hpp"
#include "include/helpers.hpp"

#include <iostream>

int main(void) {

	write_divider();
	write_title("TEST 1: Identiry Real Types");
	{
		Base* b1 = Base::generate();
		
		Base::identify(b1);
		Base::identify(*b1);
	}
	
	write_divider();
	write_title("TEST 2: Check Error with incorrect Z class");
	{
		Z* z = new Z();
		
		Base::identify(z);
		Base::identify(*z);
	}
	write_divider();
}
