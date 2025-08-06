/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 08:46:40 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/08/06 09:12:48 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMEDEQUE_HPP
#define PMERGEMEDEQUE_HPP

#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <vector>

#include "colors.hpp"

class PmergeMeDeque {
	private:
		// First Step Helpers
		void	pairAndSplit(const std::deque<int>& inputs,
								std::deque<int>& minima,
								std::deque<int>& maxima);
		
		// Internal Recursive Sort Function
		void fordJohnsonSort(std::deque<int>& sequence);

		// Insertion Helper
		void insertMinima(std::deque<int>& sorted,
							const std::deque<int>& minima);

		// Binary Insertion Utility
		std::deque<int>::const_iterator		binaryInsertPosition(const std::deque<int>& sorted, int value);
		std::deque<size_t>					generateJacobsthalIndices(size_t n);


	public:
		PmergeMeDeque();
		PmergeMeDeque(const PmergeMeDeque& other);
		PmergeMeDeque&	operator=(const PmergeMeDeque& other);
		~PmergeMeDeque();
		
		void	sort(std::deque<int>& inputs);
		void	printContainer(std::string name, const std::deque<int> container);
		bool	isSorted(const std::deque<int> sequence);
};

#endif
