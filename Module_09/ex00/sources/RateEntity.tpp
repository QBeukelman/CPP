/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RateEntity.tpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/06 20:03:33 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/29 15:52:04 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../models/RateEntity.hpp"
#include "../include/colors.hpp"

static bool isValidDate(const Date& date) {
	if (date.year <= 2000 || date.year > 2025)
		return (false);
	if (date.month < 1 || date.month > 12)
		return (false);
	if (date.day < 1 || date.day > 31)
		return (false);
	return (true);
}

template <size_t N>
ParsedResult<std::array<RateEntity, N>> parse(std::istream& in, char delimiter) {
	std::array<RateEntity, N>	rateEntities{};
	std::string					line;
	size_t						i = 0;

	// Skip the first line (e.g., "date | value")
	std::getline(in, line); // Discard the header line

	if (line.size() == 0) {
		std::cerr
			<< C_RED
			<< "ERROR: Empty file"
			<< RESET_COLOR
			<< std::endl;
		return {rateEntities, i};
	}
	
	while (std::getline(in, line)) {
		RateEntity entity;
		
		if (i >= rateEntities.size()) break ;
		
		if (line.empty()) {
			entity.error = EMPTY_LINE;
			rateEntities[i] = entity;
			i++;
			continue ;
		}

		std::string			dateStr, valueStr;
		std::stringstream	ss(line);
		if (!std::getline(ss, dateStr, delimiter)) {
			entity.error = MISSING_FIELD_DATE;
			rateEntities[i] = entity;
			i++;
			continue ;
		}
		
		Date date = {};
		if (sscanf(dateStr.c_str(), "%d-%d-%d", &date.year, &date.month, &date.day) != 3 || !isValidDate(date)) {
			entity.error = INVALID_DATE;
			entity.date = date;
			rateEntities[i] = entity;
			i++;
			continue ;
		}

		if (!std::getline(ss, valueStr)) {
			entity.error = MISSING_FIELD_VALUE;
			entity.date = date;
			rateEntities[i] = entity;
			i++;
			continue ;
		}
		
		float	value = std::stof(valueStr); // ! Validate float
		entity = {date, value, SUCCESS};
		rateEntities[i] = entity;
		i++;
	}
	return {rateEntities, i};
}

template <size_t N>
ParsedResult<std::array<RateEntity, N>> parseDataFile(std::istream& in) {
	return (parse<N>(in, ','));
}

template <size_t N>
ParsedResult<std::array<RateEntity, N>> parseInputFile(std::istream& in) {
	return (parse<N>(in, '|'));
}
