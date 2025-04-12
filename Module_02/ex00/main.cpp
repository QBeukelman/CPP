/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:45:30 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/11 12:25:47 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {

	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;

	std::cout << a.getWholeValue() << std::endl;
	std::cout << b.getWholeValue() << std::endl;
	std::cout << c.getWholeValue() << std::endl;
	
	return (0);
}
