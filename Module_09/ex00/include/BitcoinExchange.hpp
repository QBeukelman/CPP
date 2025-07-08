/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 14:02:09 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/07 14:25:59 by quentinbeuk   ########   odam.nl         */
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

#include "../sources/File.tpp"
#include "../sources/RateEntity.tpp"

class BitcoinExchange {
	private:
		// A list of known exchange rates
		File<std::array<RateEntity, ARRAY_LENGTH>>		rates;

	public:
		BitcoinExchange() = default;
		BitcoinExchange(File<std::array<RateEntity, ARRAY_LENGTH>> dataFile);

		// Open input file, and parse dates and values.
		File<std::array<RateEntity, INPUT_LENGTH>>	parseInput(const std::string& fileName);
		
		// A binary search look-up in rates.data.
		float										getRate(Date inputDate);

		// Convert all inputs using getRate().
		void										convertRates(File<std::array<RateEntity, INPUT_LENGTH>> inputFile);

		bool										isSorted();
};

#endif
