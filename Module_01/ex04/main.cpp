/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:07:07 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/11 11:20:58 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	./string_replace_exc	"test.txt" "000" "XXX"
 *								\------------------ Input file
 *										\---------- String to replace
 *												\-- Replacement string
*/

#include "File.hpp"
#include "StringProcessor.hpp"
#include <iostream>

#define OUT_FILE_SUFFIX ".append"

void		write_line(void) { std::cout << std::endl; }
void		write_divider(void) { std::cout << std::endl << "---------------------\n\n"; }

int	main(int argc, char **argv) {

	if (argc != 4) {
		std::cerr
			<< C_RED
			<< "Invalid arg count\n"
			<< RESET_COLOR;
		return (0);
	}

	std::string fileName;
	std::string s1;
	std::string s2;

	fileName = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	
	File file = File();
	file.openFile(fileName);

	write_line();
	StringProcessor	stringProcessor = StringProcessor();
	std::string newData = stringProcessor.replaceAll(file.getFileData(), s1, s2);
	if (newData.empty()) {
		return (0);
	}
	file.writeFile(fileName.append(OUT_FILE_SUFFIX), newData);
	std::cout << newData << std::endl;
}
