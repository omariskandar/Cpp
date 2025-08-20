/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:14:25 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 16:50:33 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("noname")
{
    hitpoints     = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap default-constructed: " << name << std::endl;
}

FragTrap::FragTrap(const std::string& n)
: ClapTrap(n)
{
    hitpoints = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap constructed: " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy-constructed from: " << other.name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    std::cout << "FragTrap copy-assigned: " << name << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destroyed: " << name << std::endl;
}

void FragTrap::highFivesGuys(void) const
{
    std::cout << "FragTrap " << name << " requests a positive high five! ✋" << std::endl;
}
