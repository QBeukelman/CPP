/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:41:27 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/04/04 13:36:59 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Magaphone.hpp"

Megaphone::Megaphone() : message("") {}

std::string Megaphone::str_upper(const std::string str) {
	std::string upper_str = str;

	for (size_t i = 0; i < str.size(); i++) {
		upper_str[i] = std::toupper(str[i]);
	}
	return (upper_str);
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
