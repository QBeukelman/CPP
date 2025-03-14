/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:41:27 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/03/14 11:49:15 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Magaphone.hpp"

Megaphone::Megaphone() : message("") {}

std::string Megaphone::str_upper(const std::string str) {
	std::string result;
	result.reserve(str.size());

	for (size_t i = 0; i < str.size(); i++) {
		result += std::toupper(str[i]);
	}
	return (result);
}

std::string join_args(int argc, char **argv) {
	std::string str;
	str.reserve(2048);

	for (int i = 1; i < argc; i++) {
		str.append(argv[i]);
	}
	return (str);
}

int main(int argc, char **argv) {
	Megaphone	megaphone;

	if (argc <= 1) {
		std::cout << EMPTY_MESSAGE << "\n";
		return (0);
	}
	megaphone.message = megaphone.str_upper(join_args(argc, argv));
	std::cout << megaphone.message << "\n";
	return (0);
};
