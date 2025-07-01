/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   comparator.tpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/01 09:45:43 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/01 09:46:20 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/comparator.hpp"

template <typename T> void swap(T& x, T& y) {
	T	temp;
	
	temp = x;
	x = y;
	y = temp;
}

template <typename T> T min(T x, T y) {
	if (x < y)
		return (x);
	return (y);
}

template <typename T> T max(T x, T y) {
	if (x > y)
		return (x);
	return (y);
}
