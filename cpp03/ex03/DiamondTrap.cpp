/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:38:38 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 16:48:41 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
: ClapTrap("noname_clap_name"), FragTrap("noname"), ScavTrap("noname"), name("noname")
{
    // Stats: HP from Frag, EN from Scav, DMG from Frag
    hitpoints     = 100;
    energy_points = 50;
    attack_damage = 30;
    std::cout << "DiamondTrap constructed: " << name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& n)
: ClapTrap(n + "_clap_name"), FragTrap(n), ScavTrap(n), name(n)
{
    hitpoints     = 100;
    energy_points = 50;
    attack_damage = 30;
    std::cout << "DiamondTrap constructed: " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
    std::cout << "DiamondTrap copy-constructed from: " << other.name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
    if (this != &rhs) {
        FragTrap::operator=(rhs);
        ScavTrap::operator=(rhs);
        name = rhs.name;
    }
    std::cout << "DiamondTrap copy-assigned: " << name << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destroyed: " << name << std::endl;
}

void DiamondTrap::whoAmI()
{
    // Disambiguate explicitly to be clear
    std::cout << "I am DiamondTrap \"" << name
              << "\" and my ClapTrap name is \"" << ClapTrap::name << "\""
              << std::endl;
}

