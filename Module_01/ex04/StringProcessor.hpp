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

class StringProcessor {
	public:
		StringProcessor();
		~StringProcessor();

		std::string	replaceAll(std::string content, const std::string s1, const std::string s2);	
};
