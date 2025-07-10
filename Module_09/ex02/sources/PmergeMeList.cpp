/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMeList.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/09 08:46:48 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/10 15:32:52 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMeList.hpp"

// Constructors
// _____________________________________________________________________________
PmergeMeList::PmergeMeList() {}
PmergeMeList::~PmergeMeList() {}

// Public Members
// _____________________________________________________________________________
/*
	⬅ Main sort function

	1. Create lists Minima and Maxima (comparing neighbouring pairs)
	2. Sort Maxima recursively using fordJohnsonSort()
	3. Insert Minima into Maxima using Binary Search (tournament tree)
*/
void	PmergeMeList::sort(std::list<int>& inputs) {
	std::list<int>	minima;
	std::list<int>	maxima;

	pairAndSplit(inputs, minima, maxima);
	fordJohnsonSort(maxima);
	insertMinima(maxima, minima);

	inputs = maxima;
}


void	PmergeMeList::printContainer(std::string name, const std::list<int> container) {
	std::cout << name << ": \t";
	for (const auto& item : container) {
		std::cout << item << " ";
	}
	std::cout << std::endl;
}

bool	PmergeMeList::isSorted(const std::list<int> sequence) {
	std::list<int>::const_iterator	it = sequence.begin();
	std::list<int>::const_iterator	next = it;
	next++;
	
	while (next != sequence.end()) {
		if (*it > *next) {
			std::cerr
				<< C_RED
				<< "Failed at: v[i] "
				<< *it
				<< " > v[i + 1] "
				<< *next
				<< RESET_COLOR
				<< std::endl;
			return (false);
		}
		it++;
		next++;
	}
	return (true);
}


// Private Members
// _____________________________________________________________________________

/*
	Step 1: Compare adjsent integers and split input into two vecotrs:
	- `minima`: the smaller value for each pair.
	- `maxima`: the larger value for each pair.

	If input size is odd, unpaired element is added to `maxima`.
*/
void	PmergeMeList::pairAndSplit(const std::list<int>& inputs, std::list<int>& minima, std::list<int>& maxima) {
	std::list<int>::const_iterator		it = inputs.begin();
	
	while (it != inputs.end()) {
		std::list<int>::const_iterator	next = it;
		next++;

		// If list contains odd number
		if (next == inputs.end()) {
			maxima.push_back(*it);
			break ;
		}
		
		if (*it < *next) {
			minima.push_back(*it);
			maxima.push_back(*next);		
		} else {
			minima.push_back(*next);
			maxima.push_back(*it);
		}
		std::advance(it, 2);
	}
}

/*
	Step 2: Recursivly sort sequence using Ford-Johnson algorithm

	This is the core recursive part of the algorythm:
	- Pair and split the current list.
	- Recursivly sort the `maxima` list.
	- Insert the 'minima` values into the sorted `maxima`.

	Final forted sequence is written back into the input sequence.
*/
void	PmergeMeList::fordJohnsonSort(std::list<int>& sequence) {
	if (sequence.size() <= 1)
		return ;

	std::list<int>	minima;
	std::list<int>	maxima;

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
void	PmergeMeList::insertMinima(std::list<int>& sorted, const std::list<int>& minima) {
	std::list<int>::const_iterator	it = minima.begin();

	while (it != minima.end()) {
		int								value = *it;
		std::list<int>::const_iterator	pos = linearInsertPosition(sorted, value);

		sorted.insert(pos, value);
		it++;
    }
}

/*
	Helper function to find the index where 'value' should be inserted
	into a sorted vector to maintain sort order.

	Linear search performs: O(n)
*/
std::list<int>::const_iterator	PmergeMeList::linearInsertPosition(const std::list<int>& sorted, int value) {
	std::list<int>::const_iterator	it = sorted.begin();

	while (it != sorted.end()) {
		if (*it >= value)
			return (it);
		it++;
	}
	return (sorted.end());
}
