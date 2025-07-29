/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/06 15:59:17 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/29 16:07:08 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

// Constructors
// _____________________________________________________________________________
BitcoinExchange::BitcoinExchange(File<std::array<RateEntity, ARRAY_LENGTH>> dataFile)
	: rates(dataFile) {}

File<std::array<RateEntity, INPUT_LENGTH>>	BitcoinExchange::parseInput(const std::string& fileName) {
	auto parserFunction = [](std::istream& in) {
		return (parseInputFile<INPUT_LENGTH>(in));
	};
	File<std::array<RateEntity, INPUT_LENGTH>> file(fileName, parserFunction);
	return (file);
}

// Static Members
// _____________________________________________________________________________
size_t	getMidpoint(size_t	l, size_t u) {
	return l + (u - l) / 2;
}

ValueCheck	isValidValue(float value) {
	if (std::isnan(value) || std::isinf(value) || value >= static_cast<float>(INT_MAX)) {
		std::cerr << C_RED << "ERROR: value too large." << RESET_COLOR << std::endl;
		return (INVALID_TOO_HIGH);
	}
	if (value < 0.0f) {
		std::cerr << C_RED << "ERROR: not a positive number." << RESET_COLOR << std::endl;
		return (INVALID_NEGATEVE);
	}
	return (VALID);
}

static void		writeError(RateEntity entity) {
	auto it = parseErrorMessages.find(entity.error);

	std::cout
		<< entity.date.join()
		<< '\t';

	std::string message = (it != parseErrorMessages.end()) ? it->second : "ERROR: Unknown parse error";
	std::cerr
		<< C_RED
		<< message
		<< RESET_COLOR
		<< std::endl;
}

// Public Members
// _____________________________________________________________________________
/*
	l = lower
	i = midpoint index i = l + (u - l) / 2
	u = upper
*/
float	BitcoinExchange::searchRate(Date inputDate) {
	auto		savedRates = rates.getData();
	size_t		closestLowerIndex = -1;
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
			// Not found, but this might be the closest lower index
			closestLowerIndex = i;
			continue ;
		}
	}
	if (closestLowerIndex != (size_t)-1) {
		return (savedRates[closestLowerIndex].value);
	}
	return (-1.0f);
}

void	BitcoinExchange::convertRates(File<std::array<RateEntity, INPUT_LENGTH>> inputFile) {
	auto		inputs = inputFile.getData();
	size_t		count = inputFile.getCount();
	size_t		i;
	
	i = 0;
	while (i < count) {
		if (inputs[i].error != SUCCESS) {
			writeError(inputs[i]);
			i++;
			continue ;
		}

		std::cout << inputs[i].date.join() << "\t";

		float inputRate = inputs[i].value;
		if (isValidValue(inputRate) != VALID) {
			i++;
			continue ;
		}
	
		float searchedRate = searchRate(inputs[i].date);
		float convertedRate = searchedRate * inputRate;
		if (searchedRate > 0)
			std::cout << C_BLUE << convertedRate << RESET_COLOR << std::endl;
		else
			std::cerr
				<< C_RED
				<< "ERROR: Value found was 0"
				<< RESET_COLOR
				<< std::endl;
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
