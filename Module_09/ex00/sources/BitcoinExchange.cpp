/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/06 15:59:17 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/08 07:56:45 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(File<std::array<RateEntity, ARRAY_LENGTH>> dataFile)
	: rates(dataFile) {}


// TODO: Try catch
File<std::array<RateEntity, INPUT_LENGTH>>	BitcoinExchange::parseInput(const std::string& fileName) {
	
	auto parser = [](std::istream& in) {
		return (parseInputFile<INPUT_LENGTH>(in));
	};
	
	File<std::array<RateEntity, INPUT_LENGTH>> file(fileName, parser);
	return (file);
}

size_t	getMidpoint(size_t	l, size_t u) {
	return l + (u - l) / 2;
}

/*
	l = lower
	i = midpoint index i = (l + u) / 2
	u = upper
*/
float	BitcoinExchange::getRate(Date inputDate) {
	auto		savedRates = rates.getData();
	size_t		l, i, u;

	l = 0;
	u = rates.getCount();

	// Check input
	if (u == 0)
		return (-1.0f);

	// Fix upper limit, last valid index
	u -= 1;
	
	while (l <= u) {
		i = getMidpoint(l, u);

		if (inputDate == savedRates[i].date)
			return (savedRates[i].value); // Success

		if (inputDate < savedRates[i].date) {
			if (i == 0) break ; // Prevent overflow
			// Date is less than midpoint, adjust upper limit (Midpoint becomes upper limit)
			u = i - 1;
			continue ;
		}
		if (inputDate > savedRates[i].date) {
			// Date is greater than midpoint, adjust lower limit (Midpoint becomes lower limit)
			l = i + 1;
			continue ;
		}
	}
	return (-1.0f);
}

void	BitcoinExchange::convertRates(File<std::array<RateEntity, INPUT_LENGTH>> inputFile) {
	auto		inputs = inputFile.getData();
	size_t		count = inputFile.getCount();
	size_t		i;

	// TODO: Remove sort check
	if (isSorted() == false)
		return ;
	
	i = 0;
	while (i < count) {
		std::cout << inputs[i].date.join();
	
		float savedRate = getRate(inputs[i].date);
		float convertedRate = savedRate * inputs[i].value;
		if (savedRate > 0)
			std::cout << "\tMatched rate: \t" << convertedRate << std::endl;
		else
			// TODO: Find nearest date when not found
			// TODO: Show error with incorrect inputs
			std::cout << "\tNot Found: \t" << savedRate << std::endl;
		i++;
	}
}

bool	BitcoinExchange::isSorted() {
	auto		savedRates = rates.getData();
	size_t		count = rates.getCount();
	size_t		i;

	i = 0;
	while ((i < savedRates.size() - 1) && (i < count - 1)) {
		if (savedRates[i].date > savedRates[i + 1].date) {
			std::cout << "Data not sorted at date: " << savedRates[i].date.join() << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}
