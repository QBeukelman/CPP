/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:59:23 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/04/04 10:19:37 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {

    ClapTrap newClapTrap = ClapTrap("New");
	newClapTrap.attack("Other");
    newClapTrap.takeDamage(5);
    newClapTrap.beRepaired(5);
    return (0);
}
