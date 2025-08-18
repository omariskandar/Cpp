/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:24:50 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/19 01:24:52 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ex03/Weapon.cpp
#include "Weapon.hpp"

Weapon::Weapon() : _type("") {}

Weapon::Weapon(const std::string& type) : _type(type) {}

const std::string& Weapon::getType() const {
    return _type;
}

void Weapon::setType(const std::string& type) {
    _type = type;
}
