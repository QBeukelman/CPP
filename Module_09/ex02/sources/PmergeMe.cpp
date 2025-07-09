/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/09 08:46:48 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/09 16:34:23 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

// Constructors
// _____________________________________________________________________________
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

// Public Members
// _____________________________________________________________________________
/*
	⬅ Main sort function

	1. Create lists Minima and Maxima (comparing neighbouring pairs)
	2. Sort Maxima recursively using fordJohnsonSort()
	3. Insert Minima into Maxima using Binary Search (tournament tree)
*/
void	PmergeMe::sort(const std::vector<int>& inputs) {
	std::vector<int>	minima;
	std::vector<int>	maxima;

	pairAndSplit(inputs, minima, maxima);
	fordJohnsonSort(maxima);
	insertMinima(maxima, minima);

	printVec(maxima);
}

void	PmergeMe::printVec(std::vector<int> vec) {
	for (const auto& v : vec) {
		std::cout << v << std::endl;
	}
}


// Private Members
// _____________________________________________________________________________

/*
	Step 1: Compare adjsent integers and split input into two vecotrs:
	- `minima`: the smaller value for each pair.
	- `maxima`: the larger value for each pair.

	If input size is odd, unpaired element is added to `maxima`.
*/
void	PmergeMe::pairAndSplit(const std::vector<int>& inputs, std::vector<int>& minima, std::vector<int>& maxima) {
	size_t	i;

	i = 0;
	while (i + 1 < inputs.size()) {
		if (inputs[i] < inputs[i + 1]) {
			minima.push_back(inputs[i]);
			maxima.push_back(inputs[i + 1]);
		} else {
			minima.push_back(inputs[i + 1]);
			maxima.push_back(inputs[i]);
		}
		i += 2;
	}
	if (i < inputs.size())
		maxima.push_back(inputs[i]);
}

/*
	Step 2: Recursivly sort sequence using Ford-Johnson algorithm

	This is the core recursive part of the algorythm:
	- Pair and split the current list.
	- Recursivly sort the `maxima` list.
	- Insert the 'minima` values into the sorted `maxima`.

	Final forted sequence is written back into the input sequence.
*/
void	PmergeMe::fordJohnsonSort(std::vector<int>& sequence) {
	if (sequence.size() <= 1)
		return ;

	std::vector<int>	minima;
	std::vector<int>	maxima;

	// 1: Pair and split
	pairAndSplit(sequence, minima, maxima);

	// 2: Recursively sort the maxima
	fordJohnsonSort(maxima);

	// 3: Insert minima into the sorted maxima
	insertMinima(maxima, minima);
	
	sequence = maxima;
}

/*
	Step 3: Insert each value from `minima` list into the sorted `maxima` list.
	- Find the position using binary search.
	- Inser aat calculated position to maintain sorted order.
*/
void	PmergeMe::insertMinima(std::vector<int>& sorted, const std::vector<int>& minima) {
	for (size_t i = 0; i < minima.size(); ++i) {
		int		value = minima[i];
		size_t	pos = binaryInsertPosition(sorted, value);
		
		sorted.insert(sorted.begin() + pos, value);
    }
}

/*
	Helper function to find the index where 'value' should be inserted
	into a sorted vector to maintain sort order.

	Returns the index using std::lower_bound for binary search.
*/
size_t	PmergeMe::binaryInsertPosition(const std::vector<int>& sorted, int value) {
	return (std::lower_bound(sorted.begin(), sorted.end(), value) - sorted.begin());
}
