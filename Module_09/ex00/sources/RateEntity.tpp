/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RateEntity.tpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/06 20:03:33 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/07 10:57:52 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../models/RateEntity.hpp"

// TODO: Validate date and value -> throw
template <size_t N>
ParsedResult<std::array<RateEntity, N>> parse(std::istream& in, char delimiter) {
	std::array<RateEntity, N>	rateEntities{};
	std::string					line;
	size_t						i;

	i = 0;
	while (std::getline(in, line)) {
		if (line.empty()) continue ;
		if (i >= rateEntities.size()) break ;

		std::string			dateStr, valueStr;
		std::stringstream	ss(line);
		if (!std::getline(ss, dateStr, delimiter) || !std::getline(ss, valueStr))
			continue ;
		
		Date date;
		if (sscanf(dateStr.c_str(), "%d-%d-%d", &date.year, &date.month, &date.day) != 3)
			continue ;
		
		float	value = std::stof(valueStr);
		rateEntities[i] = RateEntity{date, value};
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
