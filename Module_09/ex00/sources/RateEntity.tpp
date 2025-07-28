/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RateEntity.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:03:33 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/07/28 13:07:04 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../models/RateEntity.hpp"

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
		if (!std::getline(ss, dateStr, delimiter) || !std::getline(ss, valueStr)) {
			// TODO: Empty value
			continue ;
		}
		
		Date date;
		if (sscanf(dateStr.c_str(), "%d-%d-%d", &date.year, &date.month, &date.day) != 3) {
			// TODO: Invalid date
			continue ;
		}
		
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
