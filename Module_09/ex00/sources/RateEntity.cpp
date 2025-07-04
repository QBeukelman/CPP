/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RateEntity.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 15:17:41 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/04 15:43:30 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// ! Remove
#include <iostream>

#include "../models/RateEntity.hpp"

bool Date::operator<(const Date& other) const {
	std::cout << other.day << std::endl;
	return (false);
}

bool Date::operator==(const Date& other) const {
	std::cout << other.day << std::endl;
	return (false);
}
