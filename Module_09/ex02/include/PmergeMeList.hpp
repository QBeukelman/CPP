/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMeList.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/09 08:46:40 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/10 15:18:09 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMELIST_HPP
#define PMERGEMELIST_HPP

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

#include "colors.hpp"

class PmergeMeList {
	private:
		// First Step Helpers
		void	pairAndSplit(const std::list<int>& inputs,
								std::list<int>& minima,
								std::list<int>& maxima);
		
		// Internal Recursive Sort Function
		void fordJohnsonSort(std::list<int>& sequence);

		// Insertion Helper
		void insertMinima(std::list<int>& sorted,
							const std::list<int>& minima);

		// Binary Insertion Utility
		std::list<int>::const_iterator linearInsertPosition(const std::list<int>& sorted, int value);


	public:
		PmergeMeList();
		~PmergeMeList();
		
		void	sort(std::list<int>& inputs);
		void	printContainer(std::string name, const std::list<int> container);
		bool	isSorted(const std::list<int> sequence);
};

#endif
