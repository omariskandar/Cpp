/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:54:46 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 15:54:48 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Omar");
    ClapTrap b("Jim");
    ClapTrap c;          // noname

    a.attack("dummy target");
    a.takeDamage(4);
    a.beRepaired(2);
    a.takeDamage(20);
    a.attack("still trying");

    // burn energy
    for (int i = 0; i < 12; ++i) b.attack("wall");

    c.beRepaired(5);
    c.takeDamage(3);

    ClapTrap copy = a;   // copy-ctor
    copy.attack("ghost");

    return 0;
}
