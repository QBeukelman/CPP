/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   StringProcessor.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/16 21:15:49 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/16 22:08:12 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "StringProcessor.hpp"

StringProcessor::StringProcessor() {}
StringProcessor::~StringProcessor() {}

std::string	StringProcessor::replaceAll(std::string content, const std::string s1, const std::string s2) {
	std::string		result;
	unsigned long	pos;
	unsigned long	posEnd;
	
	if (s1.empty())
		return (content);
		
	pos = 0;
	posEnd = 0;

	while (pos != std::string::npos) {
		pos = content.find(s1, posEnd);
		result.append(content.substr(posEnd, pos - posEnd));
		if (content.find(s1, posEnd) == std::string::npos)
			break ;
		result.append(s2);
		posEnd = pos + s1.length();
	}
	return (result);
}
