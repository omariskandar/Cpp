/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:54:46 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 16:18:04 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    std::cout << "== create f ==\n";
    FragTrap f("Omar");

    std::cout << "== actions ==\n";
    f.attack("training dummy");  // costs 1 energy
    f.beRepaired(10);            // costs 1 energy
    f.takeDamage(25);
    f.highFivesGuys();

    std::cout << "== copy / assign ==\n";
    FragTrap g(f);
    FragTrap h;
    h = f;

    std::cout << "== destructors in reverse ==\n";
    return 0;
}
