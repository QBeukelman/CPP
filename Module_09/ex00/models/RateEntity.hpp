/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RateEntity.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 14:35:00 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/04 15:43:35 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <tuple>

struct Date {
	int		day;
	int		month;
	int		year;

	// Less than
	bool	operator<(const Date& other) const;
	
	// Comparison operator
	bool	operator==(const Date& other) const;
};

struct RateEntity {
	Date	date;
	int		value;
};
