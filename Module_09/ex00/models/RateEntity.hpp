/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RateEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:35:00 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/08/04 14:46:11 by qbeukelm         ###   ########.fr       */
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

enum ParseError {
	SUCCESS,
	EMPTY_LINE,
	INVALID_DATE,
	MISSING_FIELD_DATE,
	MISSING_FIELD_VALUE
};

const std::unordered_map<ParseError, std::string> parseErrorMessages = {
	{ ParseError::EMPTY_LINE,    "ERROR: Line is empty." },
	{ ParseError::INVALID_DATE,  "ERROR: Invalid date format." },
	{ ParseError::MISSING_FIELD_DATE, "ERROR: Missing date field." },
	{ ParseError::MISSING_FIELD_VALUE, "ERROR: Missing value field." },
};

template <typename T>
struct ParsedResult {
	T		data;
	size_t	count;
};

struct RateEntity {
	Date			date;
	float			value;
	ParseError		error;
};

template <size_t N>
ParsedResult<std::array<RateEntity, N>>	parseDataFile(std::istream& in);

template <size_t N>
ParsedResult<std::array<RateEntity, N>>	parseInputFile(std::istream& in);

#endif
