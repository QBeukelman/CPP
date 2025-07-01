/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.tpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/01 09:41:50 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/01 09:42:06 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

template <typename T, typename Func> void iter(T* arr, size_t size, Func func) {
	for (size_t i = 0; i < size; i++) {
		func(arr[i]);
	}
}