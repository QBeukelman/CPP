/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:46:18 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/08/04 09:08:16 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	date		| value
	------------|---------------
	2011-01-03	| 3
*/

#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "../models/RateEntity.hpp"

template<typename T>
class File {
	private:
		T			data;
		size_t		count;

	public:
		File(const std::string& fileName, std::function<ParsedResult<T>(std::istream&)> parser);

		void		readData(const std::string& fileName, std::function<ParsedResult<T>(std::istream&)> parser);
		const T&	getData() const;
		size_t		getCount() const;

		class FileException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
