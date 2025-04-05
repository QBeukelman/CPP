/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   StringProcessor.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/16 21:15:55 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/16 21:28:07 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#define C_YELLOW "\033[1;33m"
#define C_RED "\x1B[1;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define RESET_COLOR "\033[0m"

class StringProcessor {
	public:
		StringProcessor();
		~StringProcessor();

		std::string	replaceAll(std::string content, const std::string s1, const std::string s2);	
};
