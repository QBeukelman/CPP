/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RateEntity.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 14:35:00 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/08 15:38:01 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RATEENTITY_HPP
#define RATEENTITY_HPP

#define ARRAY_LENGTH 1614
#define INPUT_LENGTH 20

#include <array>
#include <string>
#include <sstream>
#include <iostream>

#include "../models/Date.hpp"

enum ValueCheck {
	VALID,
	INVALID_TOO_HIGH,
	INVALID_NEGATEVE
};

template <typename T>
struct ParsedResult {
	T		data;
	size_t	count;
};

struct RateEntity {
	Date	date;
	float	value;
};

template <size_t N>
ParsedResult<std::array<RateEntity, N>>	parseDataFile(std::istream& in);

template <size_t N>
ParsedResult<std::array<RateEntity, N>>	parseInputFile(std::istream& in);

#endif
