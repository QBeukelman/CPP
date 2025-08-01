/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/09 08:46:40 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/10 15:18:14 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

#include "colors.hpp"

class PmergeMe {
	private:
		// First Step Helpers
		void	pairAndSplit(const std::vector<int>& inputs,
								std::vector<int>& minima,
								std::vector<int>& maxima);
		
		// Internal Recursive Sort Function
		void fordJohnsonSort(std::vector<int>& sequence);

		// Insertion Helper
		void insertMinima(std::vector<int>& sorted,
							const std::vector<int>& minima);

		// Binary Insertion Utility
		size_t binaryInsertPosition(const std::vector<int>& sorted, int value);


	public:
		PmergeMe();
		~PmergeMe();
		
		void	sort(std::vector<int>& inputs);
		void	printContainer(std::string name, const std::vector<int> container);
		bool	isSorted(const std::vector<int> sequence);
};

#endif
