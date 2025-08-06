/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 08:46:40 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/08/06 09:11:23 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <vector>

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
		std::vector<int>::iterator		binaryInsertPosition(std::vector<int>& sorted, int value);
		std::vector<size_t>				generateJacobsthalIndices(size_t n);


	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();
		
		void	sort(std::vector<int>& inputs);
		void	printContainer(std::string name, const std::vector<int> container);
		bool	isSorted(const std::vector<int> sequence);
};

#endif
