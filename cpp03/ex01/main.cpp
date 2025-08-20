/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:30:40 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 16:30:42 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "== create s ==" << std::endl;
    ScavTrap s("Omar");

    std::cout << "== actions ==" << std::endl;
    s.attack("training dummy");
    s.beRepaired(10);
    s.takeDamage(25);
    s.guardGate();

    std::cout << "== copy / assign ==" << std::endl;
    ScavTrap x(s);           // copy ctor (ClapTrap then ScavTrap)
    ScavTrap y;              // default
    y = s;                   // assignment

    std::cout << "== destructors in reverse ==" << std::endl;
    return 0;
}
