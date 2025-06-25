/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/25 16:47:19 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/25 19:29:34 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <cstdint>

struct Data {
	char		c;
	std::string	str;
	int			num;
	float		f;
};

class Serializer {
	private:
		Serializer() = delete;
		Serializer(const Serializer& other) = delete;
		Serializer& operator=(const Serializer& other) = delete;
		~Serializer() = delete;

	public:
		static uintptr_t		serialize(Data* ptr);
		static Data*			deserialize(uintptr_t raw);
};

#endif
