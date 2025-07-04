/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   File.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 13:46:18 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/04 15:50:54 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
	date		| value
	------------|---------------
	2011-01-03	| 3
*/

#ifndef FILE_HPP
#define FILE_HPP

#define ROW_COUNT 2000

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "../models/RateEntity.hpp"

template<typename Container>
class File {
	private:
		Container		data;

	public:
		File();
		File(std::string fileName);
		~File();

		void	read(std::string fileName);
		void	print(void);
	
		class FileException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
