/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/28 12:11:40 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/28 12:12:05 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITER_HPP
#define WRITER_HPP

#include <iostream>
#include <string>

#define C_YELLOW "\033[33m"
#define C_RED "\x1B[1;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define RESET_COLOR "\033[0m"

void write_line();
void write_divider();
void write_title(const std::string& title);

#endif
