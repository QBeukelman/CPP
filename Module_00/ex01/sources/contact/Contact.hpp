/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:53:54 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/04/04 14:38:27 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cctype>

class Contact {
	private:
		int				index;
		std::string		firstName;
		std::string		lastName;
		std::string		nickname;
		std::string		phoneNumber;
		std::string		darkestSecret;

	public:
		Contact();
		~Contact();

		int				get_index();
		std::string		get_firstName();
		std::string		get_lastName();
		std::string		get_nickname();
		std::string		get_phoneNumber();
		std::string		get_darketSecret();

		void			set_index(int index);
		void			set_firstName(std::string firstName);
		void			set_lastName(std::string lastName);
		void			set_nickname(std::string nickname);
		void			set_phoneNumber(std::string phoneNumber);
		void			set_darkestSecret(std::string darkestSecret);
};

#endif