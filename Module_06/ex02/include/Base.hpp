/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/25 18:30:57 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/06/25 20:38:06 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_CPP
#define BASE_CPP

class Base {
	public:
		virtual ~Base();

		static Base*	generate(void);
		static void		identify(Base* p);
		static void		identify(Base& p);
};

#endif
