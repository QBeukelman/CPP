/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:13:52 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/11 11:28:35 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <map>

#define C_YELLOW "\033[1;33m"
#define C_RED "\x1B[1;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define RESET_COLOR "\033[0m"

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
