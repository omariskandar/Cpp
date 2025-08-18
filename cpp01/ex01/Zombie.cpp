/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:06:32 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/19 01:06:37 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("Unnamed") {}

Zombie::~Zombie() {
    std::cout << "[" << _name << "] destroyed\n";
}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(const std::string& name) {
    _name = name;
}