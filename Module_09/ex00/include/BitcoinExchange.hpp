/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:02:09 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/08/04 14:28:52 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	date		| value
	------------|---------------
	2011-01-03	| 3
*/

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define RATE_DATA_FILE_PATH "data/data.csv"

#include <cmath>
#include <climits>
#include <functional>

#include "../sources/File.tpp"
#include "../sources/RateEntity.tpp"
#include "colors.hpp"

class BitcoinExchange {
	private:
		// A list of known exchange rates
		File<std::array<RateEntity, ARRAY_LENGTH>>		rates;

	public:
		BitcoinExchange();
		BitcoinExchange(File<std::array<RateEntity, ARRAY_LENGTH>> dataFile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		const File<std::array<RateEntity, ARRAY_LENGTH>>	getRates() const;

		// Open input file, and parse dates and values.
		File<std::array<RateEntity, INPUT_LENGTH>>	parseInput(const std::string& fileName);

		// A binary search look-up in rates.data.
		float	searchRate(Date inputDate);

		// Convert all inputs using getRate().
		void	convertRates(File<std::array<RateEntity, INPUT_LENGTH>> inputFile);

		// Binary search requires input to be sorted.
		bool	isSorted();
};

#endif
