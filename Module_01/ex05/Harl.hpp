/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 21:13:52 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:17:54 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <map>
#include "../utils/utils.hpp"

#define DEBUG_MESSAGE "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define INFO_MESSAGE "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!"
#define WARNING_MESSAGE "I think I deserve to have some extra bacon for free. Ive been coming for years, whereas you started working here just last month."
#define ERROR_MESSAGE "This is unacceptable! I want to speak to the manager now."


enum Level {
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl {
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		std::map<std::string, void (Harl::*)()> methodMap;

	public:
		Harl() {
			methodMap["DEBUG"] = &Harl::debug;
			methodMap["INFO"] = &Harl::info;
			methodMap["WARNING"] = &Harl::warning;
			methodMap["ERROR"] = &Harl::error;
		}

		void	complain(std::string level);
};
