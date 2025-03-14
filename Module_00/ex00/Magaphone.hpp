/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Magaphone.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:41:21 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/03/14 11:48:47 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAPHONE_HPP
#define MEGAPHONE_HPP

#define EMPTY_MESSAGE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

#include <iostream>
#include <string>
#include <cctype>

class Megaphone {
	public:
		Megaphone();

		std::string message;

		std::string str_upper(const std::string str);
};

#endif
