/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:30:01 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/07/23 16:39:40 by qbeukelm         ###   ########.fr       */
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
		delete (b1);
	}
	
	write_divider();
	write_title("TEST 2: Check Error with incorrect Z class");
	{
		Z* z = new Z();
		
		Base::identify(z);
		Base::identify(*z);
		delete (z);
	}
	write_divider();
}
