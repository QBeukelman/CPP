/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMeDeque.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/09 08:46:48 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/08/05 10:15:24 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMeDeque.hpp"

// Constructors
// _____________________________________________________________________________
// Default constructor
PmergeMeDeque::PmergeMeDeque() {}

// Copy constructor
PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque& other) {
	(void)other;
}

// Assignment operator
PmergeMeDeque& PmergeMeDeque::operator=(const PmergeMeDeque& other) {
	if (this != &other) {}
	return *this;
}

// Destructor
PmergeMeDeque::~PmergeMeDeque() {}


// Public Members
// _____________________________________________________________________________
/*
	⬅ Main sort function

	1. Create lists Minima and Maxima (comparing neighbouring pairs)
	2. Sort Maxima recursively using fordJohnsonSort()
	3. Insert Minima into Maxima using Binary Search (tournament tree)
*/
void	PmergeMeDeque::sort(std::deque<int>& inputs) {
	std::deque<int>	minima;
	std::deque<int>	maxima;

	pairAndSplit(inputs, minima, maxima);
	fordJohnsonSort(maxima);
	insertMinima(maxima, minima);

	inputs = maxima;
}


void	PmergeMeDeque::printContainer(std::string name, const std::deque<int> container) {
	std::cout << name << ": \t";
	for (const auto& item : container) {
		std::cout << item << " ";
	}
	std::cout << std::endl;
}

bool	PmergeMeDeque::isSorted(const std::deque<int> sequence) {
	std::deque<int>::const_iterator	it = sequence.begin();
	std::deque<int>::const_iterator	next = it;
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
void	PmergeMeDeque::pairAndSplit(const std::deque<int>& inputs, std::deque<int>& minima, std::deque<int>& maxima) {
	std::deque<int>::const_iterator		it = inputs.begin();
	
	while (it != inputs.end()) {
		std::deque<int>::const_iterator	next = it;
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
void	PmergeMeDeque::fordJohnsonSort(std::deque<int>& sequence) {
	if (sequence.size() <= 1)
		return ;

	std::deque<int>	minima;
	std::deque<int>	maxima;

	// 1: Pair and split
	pairAndSplit(sequence, minima, maxima);

	// 2: Recursively sort the maxima
	fordJohnsonSort(maxima);

	// 3: Insert minima into the sorted maxima
	insertMinima(maxima, minima);

	sequence = maxima;
}

/*
	Step 3.1: Generates a sequence of indices based on the Jacobsthal number sequence
	and completes it to cover all indices up to size `n`.

	Jacobsthal sequence:
		J(0) = 0
		J(1) = 1
		J(n) = J(n - 1) + 2 * J(n - 2)

	This function is used to determine the order in which elements from the
	`minima` list are inserted into the sorted `maxima` list in the 
	Ford-Johnson Merge-Insertion Sort. The Jacobsthal order minimizes 
	comparisons by distributing inserts more evenly across the list.

	Parameters:
		n – total number of minima elements

	Returns:
		A deque of `n` indices representing the order in which elements 
		should be inserted, starting with Jacobsthal indices, followed 
		by any remaining indices in increasing order.
*/
std::deque<size_t> PmergeMeDeque::generateJacobsthalIndices(size_t n) {
	std::deque<size_t>	sequence;
	size_t 				j1 = 1, j2 = 0;

	if (n == 0)
		return (sequence);

	sequence.push_back(0);  // J(0) = 0

	while (true) {
		size_t next = j1 + 2 * j2;
		if (next >= n)
			break;
		sequence.push_back(next);
		j2 = j1;
		j1 = next;
	}

	// Fill in missing indices not covered by the Jacobsthal sequence
	std::deque<size_t>		result;
	std::vector<bool>		seen(n, false);
	for (size_t idx : sequence) {
		if (!seen[idx]) {
			result.push_back(idx);
			seen[idx] = true;
		}
	}
	for (size_t i = 0; i < n; ++i) {
		if (!seen[i])
			result.push_back(i);
	}

	return (result);
}

/*
	Step 3.2: Insert each value from `minima` list into the sorted `maxima` list.
	- Find the position using binary search.
	- Insert at calculated position to maintain sorted order.
*/
void PmergeMeDeque::insertMinima(std::deque<int>& sorted, const std::deque<int>& minima) {
	std::deque<size_t>	insertionOrder = generateJacobsthalIndices(minima.size());

	for (size_t i : insertionOrder) {
		int value = minima[i];
		std::deque<int>::const_iterator pos = binaryInsertPosition(sorted, value);
		sorted.insert(pos, value);
	}
}

/*
	Helper function to find the iterator where 'value' should be inserted
	into a sorted vector to maintain sort order.

	Uses std::lower_bound for binary search (O(log n)).

	Returns:
		Iterator pointing to the correct insert position in `sorted`.
*/
std::deque<int>::const_iterator		PmergeMeDeque::binaryInsertPosition(const std::deque<int>& sorted, int value) {
	return (std::lower_bound(sorted.begin(), sorted.end(), value));
}
