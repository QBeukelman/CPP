/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.tpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/03 10:16:20 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/03 14:51:36 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T& container, int value) {
	auto it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw std::runtime_error("Exception: Value was not found in container.");
	}
	return (it);
}
