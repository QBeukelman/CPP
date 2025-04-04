/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:19:52 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/04 17:19:58 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void		write_line(void) { std::cout << std::endl; }
void		write_divider(void) { std::cout << std::endl << "---------------------\n\n"; }

int main(void) {
	
	write_line();
	Zombie*	heapZombie = Zombie::newZombie("HeapZombie");
	heapZombie->announce();
	delete (heapZombie);

	write_divider();
	Zombie::randomChump("StackZombie");
	write_line();
	
	return (0);
}
