/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Date.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/06 20:17:56 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/07 14:47:58 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
#define DATE_HPP

#include <string>
#include <sstream>
#include <iomanip>

struct Date {
	int		day;
	int		month;
	int		year;

	std::string		join() const;
	bool			operator<(const Date& other) const;
	bool			operator>(const Date& other) const;
	bool			operator==(const Date& other) const;
};

#endif
