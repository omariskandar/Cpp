/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:25:47 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/19 01:25:49 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
public:
    explicit HumanB(const std::string& name); // may start unarmed
    void setWeapon(Weapon& weapon);           // can arm later
    void attack() const;

private:
    std::string _name;
    Weapon*     _weapon; // pointer: can be NULL (unarmed)
};

#endif