/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:41:43 by oiskanda          #+#    #+#             */
/*   Updated: 2025/08/20 16:01:06 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("noname"), hitpoints(10), attack_damage(0), energy_points(10)
{
    std::cout << "ClapTrap default-constructed: " << name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitpoints(10), attack_damage(0), energy_points(10)
{
    std::cout << "ClapTrap constructed: " << this->name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), hitpoints(other.hitpoints),
      attack_damage(other.attack_damage), energy_points(other.energy_points)
{
    std::cout << "ClapTrap copy-constructed: " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    if (this != &rhs)
    {
        name = rhs.name;
        hitpoints = rhs.hitpoints;
        attack_damage = rhs.attack_damage;
        energy_points = rhs.energy_points;
    }
    std::cout << "ClapTrap copy-assigned: " << name << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destroyed: " << name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hitpoints <= 0) {
        std::cout << "ClapTrap " << name << " can’t attack: no hit points left!" << std::endl;
        return;
    }
    if (energy_points <= 0) {
        std::cout << "ClapTrap " << name << " can’t attack: no energy points left!" << std::endl;
        return;
    }
    --energy_points;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attack_damage << " points of damage! "
              << "(HP=" << hitpoints << ", EN=" << energy_points << ")"
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitpoints <= 0) {
        std::cout << "ClapTrap " << name << " is already down!" << std::endl;
        return;
    }
    hitpoints -= static_cast<int>(amount);
    if (hitpoints < 0) hitpoints = 0;

    std::cout << "ClapTrap " << name << " takes " << amount << " damage! "
              << "(HP=" << hitpoints << ", EN=" << energy_points << ")"
              << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitpoints <= 0) {
        std::cout << "ClapTrap " << name << " can’t repair: no hit points left!" << std::endl;
        return;
    }
    if (energy_points <= 0) {
        std::cout << "ClapTrap " << name << " can’t repair: no energy points left!" << std::endl;
        return;
    }
    --energy_points;
    hitpoints += static_cast<int>(amount);

    std::cout << "ClapTrap " << name << " repairs " << amount << " hit points! "
              << "(HP=" << hitpoints << ", EN=" << energy_points << ")"
              << std::endl;
}
