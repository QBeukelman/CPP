/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:56:03 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/11 12:25:37 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int					_wholeValue;
		static const int	_fractionalValue = 8;

	public:
		Fixed();								// Default constructor
		Fixed(const Fixed& other);				// Copy constructor
		Fixed& operator=(const Fixed& other);	// Copy assignment operator
		~Fixed();								// Destructor

		int		getWholeValue(void) const;
		void	setWholeValue(int const newValue);
};

#endif
