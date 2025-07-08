/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Date.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/06 20:17:53 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/07 15:13:02 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../models/Date.hpp"

std::string	Date::join() const {
	std::ostringstream oss;
	oss << std::setw(2) << std::setfill('0') << day
		<< " - "
		<< std::setw(2) << std::setfill('0') << month
		<< " - "
		<< year;
	return (oss.str());
}

bool	Date::operator<(const Date& other) const {
	if (year != other.year)
		return year < other.year;
	if (month != other.month)
		return month < other.month;
	return day < other.day;
}

bool	Date::operator>(const Date& other) const {
	if (year != other.year)
		return year > other.year;
	if (month != other.month)
		return month > other.month;
	return day > other.day;
}

bool	Date::operator==(const Date& other) const {
	return (day == other.day && month == other.month && year == other.year);
}
