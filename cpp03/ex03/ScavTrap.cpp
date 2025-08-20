/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:30:26 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 16:30:27 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
: ClapTrap("noname")
{
    hitpoints     = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap constructed: " << name << std::endl;
}

ScavTrap::ScavTrap(const std::string& n)
: ClapTrap(n)
{
    hitpoints     = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap constructed: " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
: ClapTrap(other)
{
    std::cout << "ScavTrap copy-constructed from: " << other.name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    std::cout << "ScavTrap copy-assigned: " << name << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destroyed: " << name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hitpoints <= 0) {
        std::cout << "ScavTrap " << name << " can’t attack: no hit points left!" << std::endl;
        return;
    }
    if (energy_points <= 0) {
        std::cout << "ScavTrap " << name << " can’t attack: no energy points left!" << std::endl;
        return;
    }
    --energy_points;
    std::cout << "ScavTrap " << name << " slashes " << target
              << ", causing " << attack_damage << " points of damage! "
              << "(HP=" << hitpoints << ", EN=" << energy_points << ")"
              << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
