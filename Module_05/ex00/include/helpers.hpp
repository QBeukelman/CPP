/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/19 15:44:34 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/19 15:45:59 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <iostream>
#include <string>

#define C_YELLOW "\033[33m"
#define RESET_COLOR "\033[0m"

void write_line();
void write_divider();
void write_title(const std::string& title);

#endif
